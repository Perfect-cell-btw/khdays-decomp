/* Kick anim 4, set bit 0 of the +0x3b4 status byte, then dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
struct b8 { unsigned int f : 8; };
extern int Ov253_TauntTick(int);
void Ov253_AiEnterTaunt(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 4, 0);
    ((struct b8 *)(*(int *)(*(int *)owner + 0x3b4) + 8))->f |= 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_TauntTick);
}
