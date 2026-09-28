/* c634 handler: notify Ov107_PostTagUpdate(owner,0x10,0), push a shared constant vec
 * (data_02041dc8, mode 0xb) then the owner's local-offset vec (owner+0x494, mode 4) via
 * func_ov107_020c0b90, clear obj+0x62, and dispatch into Ov228_GuardedPushOffset. */

#include "nitro/fx.h"

extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void func_ov107_020c0b90(int owner, int mode, VecFx32 v, int flag);
extern void SetIndexedSlot(int self, int index, void *cb);
extern VecFx32 data_02041dc8;
extern void Ov228_GuardedPushOffset(void);
void Ov228_PushConstThenOffset(int self) {
    int *obj = *(int **)(self + 4);
    Ov107_PostTagUpdate(*obj, 0x10, 0);
    func_ov107_020c0b90(*obj, 0xb, data_02041dc8, 0);
    func_ov107_020c0b90(*obj, 4, *(VecFx32 *)(*obj + 0x494), 0);
    *(char *)((char *)obj + 0x62) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov228_GuardedPushOffset);
}
