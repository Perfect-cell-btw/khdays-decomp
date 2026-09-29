/* Prime the fields, kick anim 8, notify 020cd524 and 020cd628, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov259_MirrorPartnerPose(int, int, int);
extern int Ov259_ArmPartnerCue(int, int, int);
extern int Ov259_GuardEndTick(int);
void Ov259_AiEnterDash(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x68) = 0;
    *(signed char *)(owner + 0xac) = 0;
    *(int *)(owner + 0x88) = 0xc00;
    *(int *)(owner + 0x94) = 0x1e;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 8, 0);
    Ov259_MirrorPartnerPose(param_1, 8, 0);
    Ov259_ArmPartnerCue(param_1, 0x11, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_GuardEndTick);
}
