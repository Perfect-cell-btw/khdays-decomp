/* Seed the state (+0x88=0x900, clear +0x58/+0x68/+0x74/+0xac, +0x94 by the +0x4c mode). If +0xad
 * holds a queued sub-state apply it and reset, otherwise kick the +0x4c-selected anims and dispatch. */

#include "game/enemy_common.h"

extern int Ov259_MirrorPartnerPose(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov259_ThinkSlot(int);
void Ov259_AiResetMoveState(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x88) = 0x900;
    *(int *)(owner + 0x58) = 0;
    *(int *)(owner + 0x68) = 0;
    *(int *)(owner + 0x74) = 0;
    *(unsigned char *)(owner + 0xac) = 0;
    *(int *)(owner + 0x94) = *(int *)(owner + 0x4c) == 0 ? 0xb4 : 0x32;
    signed char ad = *(signed char *)(owner + 0xad);
    if (ad != -1) {
        *(unsigned char *)(*(int *)owner + 0x1c7) = ad;
        *(signed char *)(owner + 0xad) = -1;
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), *(int *)(owner + 0x4c) == 0 ? 0 : 2, 1);
    Ov259_MirrorPartnerPose(param_1, (signed char)(*(int *)(owner + 0x4c) == 0 ? 0 : 2), 1);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov259_ThinkSlot);
}
