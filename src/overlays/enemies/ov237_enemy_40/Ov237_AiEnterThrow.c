/* Kick anim 0xb, arm the 020c5af8 timer, prime fields, then dispatch. */

#include "game/enemy_common.h"

extern int Ov107_BuildAndSendUpdate(int, int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov237_ThrowTick(int);
void Ov237_AiEnterThrow(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0xb, 0);
    Ov107_BuildAndSendUpdate(*(int *)owner, 0x12d, 6, *(int *)(owner + 0x38));
    *(int *)(owner + 0x30) = 0;
    *(signed char *)(owner + 0x55) = 2;
    *(signed char *)(*(int *)owner + 0x49c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov237_ThrowTick);
}
