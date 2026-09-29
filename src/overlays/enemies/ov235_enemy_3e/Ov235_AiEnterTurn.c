/* Unless the child gate is set, kick anim 0x1c and the +0x3a8 sub-anim 0x15, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov235_TurnTick(int);
void Ov235_AiEnterTurn(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 0xc)) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x1c, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x3a8), 0x15, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov235_TurnTick);
}
