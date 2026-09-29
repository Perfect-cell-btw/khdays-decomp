/* Kick the primary anim 0x20 and the +0x450 sub-anim 0x11, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_WalkEntryTick(int);
void Ov256_AiEnterWalk(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x20, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x450), 0x11, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_WalkEntryTick);
}
