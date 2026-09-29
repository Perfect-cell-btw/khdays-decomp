/* Snapshot the +0x30 vector, decay the +0x34 accumulator by delta*30/32, then dispatch if ready. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
struct w3 { int a, b, c; };
struct bit0 { unsigned char b : 1; };
extern int Ov247_AiLandPickAction(int);
void Ov247_AiJumpFallTick(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(struct w3 *)(owner + 0x18) = *(struct w3 *)(owner + 0x30);
    int delta = *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(owner + 0x34) -= (int)((((long long)(delta * 30) << 7) + 0x800) >> 12);
    if ((((struct bit0 *)(*(int *)owner + 0x17a))->b) == 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 4, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov247_AiLandPickAction);
}
