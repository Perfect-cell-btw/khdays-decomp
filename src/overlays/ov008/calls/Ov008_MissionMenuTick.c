/* Ov008_MissionMenuTick -- main-menu tick, returns the next scene state (0 = stay).
 * While the menu is still opening (Ov008_Link_GetField49C) it only waits for the open animation
 * to finish and then advances to Ov008_MissionInitVideoScene. Once open, a committed selection
 * (Ov008_MissionCommitEntry) clears the 8-byte selection block at OBJ+0x38, stops the menu tweens
 * and the cursor, and advances to Ov008_UpdateMissionMenuOptionScreen.
 *
 * PROVENANCE: byte-identical twin of Ov006_MissionMenuTick -- same code, this overlay's own
 * globals, propagated mechanically and verified byte-exact.
 * The scene-identity phrasing that came with the twin source (Mission Mode / char select /
 * ov025 panel) is the REP's, NOT established for ov008, so it was removed rather than
 * carried over. What IS measured: ov008's own strings include UI/mlt/res.p2 (the same pack
 * ov006 loads) plus UI/cm/*.p2 and ba/ch/*, so resource detail naming those is sound; the
 * scene label is not. The offsets and logic below are this function's -- the code is
 * byte-identical to the rep.
 */
extern int  Ov008_Link_GetField49C(void);
extern int  Ov008_Link_GetField4F0(void);
extern int  Ov008_MissionCommitEntry(void);
extern void MI_CpuFill8(void *dst, int data, unsigned int size);
extern void Ov008_RequestMenuState(int a, int b, int c);
extern void Ov008_MissionScene_SetByte95AC(int a);
extern void Ov008_MissionInitVideoScene(void);
extern void Ov008_UpdateMissionMenuOptionScreen(void);
extern int  data_ov008_02090fa0;

void *Ov008_MissionMenuTick(void) {
    void *next = 0;
    if (Ov008_Link_GetField49C() == 0) {
        if (Ov008_Link_GetField4F0() != 0) {
            return (void *)Ov008_MissionInitVideoScene;
        }
        return next;
    }
    if (Ov008_MissionCommitEntry() != 0) {
        void *sel = *(char **)&data_ov008_02090fa0 + 0x38;
        /* `clear` is next's still-zero value: the ROM keeps both in the same callee-saved
         * register and reloads it with Ov008_UpdateMissionMenuOptionScreen before the fill call, so the
         * capture-then-reassign order below is what reproduces its schedule. */
        int clear = (int)next;
        next = (void *)Ov008_UpdateMissionMenuOptionScreen;
        MI_CpuFill8(sel, clear, 8);
        Ov008_RequestMenuState(0, 0, 0);
        Ov008_MissionScene_SetByte95AC(0);
    }
    return next;
}
