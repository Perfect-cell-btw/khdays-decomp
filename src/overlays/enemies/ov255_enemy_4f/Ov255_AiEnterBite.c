/* Kick anim 0xd and the +0x3a4 sub-anim 0xc, reset four fields, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov255_BiteTick(int);
void Ov255_AiEnterBite(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xd, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3a4), 0xc, 0);
    *(int *)(owner + 0x44) = 0;
    *(signed char *)(owner + 0x63) = 0;
    *(int *)(owner + 0x50) = 0;
    *(signed char *)(owner + 0x65) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov255_BiteTick);
}
