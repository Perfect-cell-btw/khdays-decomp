/* Ov008_MissionCommitEntry -- commit or cancel the highlighted menu entry.
 * When the scene reports state 1 the entry is accepted: the scene object moves to the
 * accept state (Ov008_MissionExpireRows), the 0x3ec-byte selection scratch at obj+0x40 is
 * wiped, the pending-transition slot at obj+0x28 is cleared and the sound is silenced.
 * Otherwise it moves to the cancel state (Ov008_MissionSceneIdleCallback) and runs the scene tick.
 * Returns whether the entry was accepted.
 *
 * PROVENANCE: byte-identical twin of Ov006_MissionCommitEntry -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */
extern int  Game_PollSceneAlive(void);
extern void Obj_SetField14(int scene, int next);
extern void MI_CpuFill8(void *dst, int data, unsigned int size);
extern void Ov105_WH_SetReceiver(int a);
extern void Ov008_MissionDriveSound(void);
extern void Ov008_MissionExpireRows(void);
extern void Ov008_MissionSceneIdleCallback(void);
extern int  data_ov008_02090f24;

#define OBJ   (*(int **)&data_ov008_02090f24)
#define SCENE (*(int *)((int)&data_ov008_02090f24 + 4))

int Ov008_MissionCommitEntry(void) {
    int accepted = 0;
    if (Game_PollSceneAlive() == 1) {
        Obj_SetField14(SCENE, (int)Ov008_MissionExpireRows);
        MI_CpuFill8((char *)OBJ + 0x40, accepted, 0x3ec);
        OBJ[0xa] = accepted;
        Ov105_WH_SetReceiver(accepted);
        accepted = 1;
    } else {
        Obj_SetField14(SCENE, (int)Ov008_MissionSceneIdleCallback);
        Ov008_MissionDriveSound();
    }
    return accepted;
}
