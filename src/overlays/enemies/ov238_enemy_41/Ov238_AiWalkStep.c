/* Push the socket at obj+0x3e0+0x2c into 020d07f0; unless busy, tick down +0x2d, kick anim 1,
 * restart sub-anim 020c9ee8, set +0x31=2, clear +0x20 and dispatch 020d1594. */

#include "game/enemy_common.h"

extern int Ov238_TurnVelocity(int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov238_AdvanceTick(int);
void Ov238_AiWalkStep(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov238_TurnVelocity(param_1, *(int *)(*(int *)owner + 0x3e0) + 0x2c);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(unsigned char *)(owner + 0x2d) -= 1;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 1, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3e0), 0, 0);
    *(unsigned char *)(owner + 0x31) = 2;
    *(int *)(owner + 0x20) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_AdvanceTick);
}
