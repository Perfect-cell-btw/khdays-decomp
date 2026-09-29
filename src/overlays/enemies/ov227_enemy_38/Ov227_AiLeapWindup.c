/* If Ov227_MeasureTargetGap fails (<0), dispatch with a null handler and return.
 * Otherwise, unless the grandchild is busy (+0xad), set anim 0x14 and dispatch. */

#include "game/enemy_common.h"

extern int Ov227_MeasureTargetGap(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov227_LeapTick(void);
void Ov227_AiLeapWindup(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (Ov227_MeasureTargetGap(param_1, 0) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
        return;
    }
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate((Actor *)(*(int *)child), 0x14, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov227_LeapTick);
}
