#include "game/enemy_common.h"

extern void func_ov107_020c0b90(int owner, int mode, VecFx32 v, int flag);
extern void SetIndexedSlot(int self, int index, void *cb);
extern VecFx32 data_02041dc8;
extern void Ov229_GuardedPushOffset(void);
void Ov229_PushConstThenOffset(int self) {
    int *obj = *(int **)(self + 4);
    Ov107_PostTagUpdate((Actor *)(*obj), 0x10, 0);
    func_ov107_020c0b90(*obj, 0xb, data_02041dc8, 0);
    func_ov107_020c0b90(*obj, 4, *(VecFx32 *)(*obj + 0x494), 0);
    *(char *)((char *)obj + 0x62) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov229_GuardedPushOffset);
}
