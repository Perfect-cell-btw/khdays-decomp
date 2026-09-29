/* Kick anim 0xd, clear the 0x40 bit of the hw60 hi byte, arm the 0x15f/0xb timer with +0xc,
 * clear +0x4e/+0x2c and dispatch 020d2c88. */

#include "game/enemy_common.h"

extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov268_BounceShotTick(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov268_AiEnterBounceShot(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xd, 1);
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~0x40;
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x15f, 0xb, *(int *)(owner + 0xc));
    *(unsigned char *)(owner + 0x4e) = 0;
    *(int *)(owner + 0x2c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov268_BounceShotTick);
}
