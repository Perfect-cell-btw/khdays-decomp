/* On sub-state 7 advance +0x44 by 0x3244 and mirror into +0x40, then reset anim 0 and dispatch. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_ThinkSlot(int);
void Ov256_AiEnterThink(int param_1) {
    int owner = *(int *)(param_1 + 4);
    if (*(signed char *)(*(int *)owner + 0x1c8) == 7) {
        *(int *)(owner + 0x44) += 0x3244;
        *(int *)(owner + 0x40) = *(int *)(owner + 0x44);
    }
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_ThinkSlot);
}
