/* Enter the burst state: flag +0x4c, store angle/5 into +0x9c, clear +0x68/+0xac, flag the node's
 * +0x42c, kick anim 4, run 020cd524 and the 0x15/0x1e48 020cd628 pulse, then dispatch 020cf764. */

#include "game/enemy_common.h"

extern int Ov259_MirrorPartnerPose(int, int, int);
extern int Ov259_ArmPartnerCue(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov259_LandingTick(int);
void Ov259_AiEnterFinisher(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x4c) = 1;
    *(int *)(owner + 0x9c) = (short)*(short *)(*(int *)owner + 0x21a) / 5;
    *(int *)(owner + 0x68) = 0;
    *(unsigned char *)(owner + 0xac) = 0;
    *(int *)(*(int *)owner + 0x42c) = 1;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 4, 0);
    Ov259_MirrorPartnerPose(param_1, 4, 0);
    Ov259_ArmPartnerCue(param_1, 0x15, 0x1e48);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_LandingTick);
}
