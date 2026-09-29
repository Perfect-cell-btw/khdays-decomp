/* Unless busy, tick +0x30; dispatch 020d0540 when either the active node's sub-state hit 0xc or,
 * when idle, the counter reached 3; otherwise reset anim 0. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov237_AiEnterReaction(int);
void Ov237_AiComboCount(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(owner + 4) + 0xad) != 0) return;
    *(int *)(owner + 0x30) += 1;
    int flag = 0;
    int obj = *(int *)owner;
    int t = *(int *)(obj + 0x4ac);
    if (t != 0) {
        if (*(signed char *)(*(int *)(obj + 0x4a4) + 0x1c6) == 0xc) flag = 1;
    }
    if (t == 0) {
        if (*(int *)(owner + 0x30) >= 3) flag = 1;
    }
    if (flag != 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov237_AiEnterReaction);
    } else {
        Ov107_PostTagUpdate((Actor *)obj, 0, 0);
    }
}
