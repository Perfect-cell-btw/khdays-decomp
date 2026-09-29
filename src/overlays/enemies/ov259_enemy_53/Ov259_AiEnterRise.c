/* Kick anim 1, notify 020cd524, reset the motion fields, set +0x94=0x19, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov259_MirrorPartnerPose(int, int, int);
extern int Ov259_RiseTick(int);
void Ov259_AiEnterRise(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 0);
    Ov259_MirrorPartnerPose(param_1, 1, 1);
    *(int *)(owner + 0x68) = 0;
    *(signed char *)(owner + 0xac) = 0;
    *(int *)(owner + 0x98) = 0;
    *(int *)(owner + 0xa8) = 0;
    *(int *)(owner + 0x6c) = 0;
    *(int *)(owner + 0x94) = 0x19;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_RiseTick);
}
