/* Reset an enemy's melee-reaction AI state: cancel the current reaction (Ov107_PostTagUpdate mode
 * 9), clear the timers/flags, decrement the cooldown if positive, pick a fresh reaction bias
 * (3 one time in four, else 1), and re-register the per-frame think callback.
 *
 * The `+ (v - v)` term is the documented copy artifact for RandNextScaled's 64-bit return
 * (K&R extern), which the ROM tests with `adds r0,r0,#0`. */

#include "game/enemy_common.h"
#include "game/engine.h"

extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov270_BeginSwing(void);

void Ov270_ResetReactionAi(int param_1, int param_2, int param_3, int param_4) {
    int v;
    int *node = *(int **)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*node), 9, 0);
    *(unsigned char *)((char *)node + 0x50) = 0;
    *(int *)((char *)node + 0x30) = 0;
    if (*(int *)((char *)node + 0x44) > 0) {
        *(int *)((char *)node + 0x44) = *(int *)((char *)node + 0x44) - 1;
    }
    *(int *)((char *)node + 0x4c) = (RandNextScaled(4) + (v - v) == 0) ? 3 : 1;
    *(unsigned char *)((char *)node + 0x51) = 0;
    *(unsigned char *)((char *)node + 0x53) = 0;
    *(int *)((char *)node + 0x54) = 0;
    SetIndexedSlot(param_1, *(signed char *)((char *)param_1 + 0x20), &Ov270_BeginSwing);
}
