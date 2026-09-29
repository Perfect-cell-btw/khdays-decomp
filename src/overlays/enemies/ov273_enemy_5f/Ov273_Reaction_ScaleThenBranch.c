/* c634 handler: set obj->f48 = self->f0->f2c*30/10, query Ov107_FindNearestObject; if it
 * returns 0, latch owner->+0x1c7 = 2 and dispatch with null cb. Otherwise bail if
 * *(obj->f8) is set; else reset obj->f1c, set obj->f48 = self->f0->f2c*30/2, notify
 * Ov107_PostTagUpdate(owner, 2, 1), and dispatch via SetIndexedSlot. */

#include "game/enemy_common.h"

extern int Ov107_FindNearestObject(int owner, int a);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov273_CloseInTick(void);
void Ov273_Reaction_ScaleThenBranch(int self) {
    int obj = *(int *)(self + 4);
    *(int *)(obj + 0x48) = *(int *)(*(int *)self + 0x2c) * 30 / 10;
    *(int *)(obj + 0x24) = Ov107_FindNearestObject(*(int *)obj, 0);
    if (*(int *)(obj + 0x24) == 0) {
        *(unsigned char *)(*(int *)obj + 0x1c7) = 2;
        SetIndexedSlot(self, *(signed char *)(self + 0x20), 0);
        return;
    }
    if (*(unsigned char *)(*(int *)(obj + 8)) != 0) {
        return;
    }
    *(int *)(obj + 0x1c) = 0;
    *(int *)(obj + 0x48) = *(int *)(*(int *)self + 0x2c) * 30 / 2;
    Ov107_PostTagUpdate((Actor *)(*(int *)obj), 2, 1);
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov273_CloseInTick);
}
