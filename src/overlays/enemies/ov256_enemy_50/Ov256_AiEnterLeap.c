/* Clear +0x4c, kick primary anim 0x17 and the +0x450 sub-anim 9, then dispatch via c634. */

#include "game/enemy_common.h"

extern int SetIndexedSlot(int, int, void *);
extern int Ov256_LeapEntryTick(int);
void Ov256_AiEnterLeap(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x4c) = 0;
    Ov107_PostTagUpdate((Actor *)(*(int *)owner), 0x17, 0);
    Ov107_StartAnim(*(int *)(*(int *)owner + 0x450), 9, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov256_LeapEntryTick);
}
