#include "game/ov006_mission_mode_select.h"
/* Ov006_MissionCommitEntry -- Mission Mode: commit or cancel the highlighted menu entry.
 * When the scene reports state 1 the entry is accepted: the scene object moves to the
 * accept state (Ov006_MissionExpireRows), the 0x3ec-byte selection scratch at obj+0x40 is
 * wiped, the pending-transition slot at obj+0x28 is cleared and the sound is silenced.
 * Otherwise it moves to the cancel state (Ov006_MissionSceneIdleCallback) and runs the scene tick.
 * Returns whether the entry was accepted. */
extern int  Game_PollSceneAlive(void);
extern void Obj_SetField14(int scene, int next);
extern void MI_CpuFill8(void *dst, int data, unsigned int size);
extern void Ov105_WH_SetReceiver(int a);
extern void Ov006_MissionDriveSound(void);
extern void Ov006_MissionExpireRows(void);
extern void Ov006_MissionSceneIdleCallback(void);
#define MISSION_CONTEXT (data_ov006_020565e4.pContext)

#define OBJ   ((int *)data_ov006_020565e4.pContext)
#define SCENE ((int)data_ov006_020565e4.pController)

int Ov006_MissionCommitEntry(void) {
    int accepted = 0;
    if (Game_PollSceneAlive() == 1) {
        Obj_SetField14(SCENE, (int)Ov006_MissionExpireRows);
        MI_CpuFill8((char *)OBJ + 0x40, accepted, 0x3ec);
        OBJ[0xa] = accepted;
        Ov105_WH_SetReceiver(accepted);
        accepted = 1;
    } else {
        Obj_SetField14(SCENE, (int)Ov006_MissionSceneIdleCallback);
        Ov006_MissionDriveSound();
    }
    return accepted;
}
