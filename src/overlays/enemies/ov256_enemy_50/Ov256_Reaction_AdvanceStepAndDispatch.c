#include "game/enemy_common.h"

extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov256_AiClawStepLoop(void);
void Ov256_Reaction_AdvanceStepAndDispatch(int self) {
    int obj = *(int *)(self + 4);
    Ov107_PostTagUpdate((Actor *)(*(int *)obj), *(int *)(obj + 0x54) + 5, 0);
    *(int *)(obj + 0x54) += 1;
    if (*(int *)(obj + 0x54) == 1) {
        *(int *)(obj + 0x54) = *(volatile int *)(obj + 0x54) + 1;
    }
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov256_AiClawStepLoop);
}
