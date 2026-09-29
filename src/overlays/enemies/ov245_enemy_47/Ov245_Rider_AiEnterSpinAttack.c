/* Kick anim 4, clear +0x40/+0x48/+0x49, arm the 020c5af8 timer, then dispatch. */

#include "game/enemy_common.h"

extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_SpinAttackTick(int);
void Ov245_Rider_AiEnterSpinAttack(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 4, 0);
    *(int *)(owner + 0x40) = 0;
    *(signed char *)(owner + 0x48) = 0;
    *(signed char *)(owner + 0x49) = 0;
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x11a, 7, *(int *)(owner + 0xc));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_SpinAttackTick);
}
