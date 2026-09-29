/* c634 handler (charge-then-break variant): while obj->f49==0, charge obj->f2c by
 * self->f0->f2c; at >=0x99a fire Ov107_BuildAndSendUpdate(owner, 0x154, 4, owner->f3c4+4)
 * and latch f49=1. Bail if *(obj->f4 + 0xad) is set. Clear owner->+0x1ae bit0, set
 * bit0 of owner->f3b8->+8 and f3b4->+8, Ov107_PostTagUpdate(owner, 6, 1), reset
 * obj->f2c, dispatch via SetIndexedSlot. owner re-read per section. */

#include "game/enemy_common.h"

extern void Ov107_BuildAndSendUpdate(int owner, int a, int b, int c);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov209_AiChargeTimeout(void);
struct b8 { unsigned int f:8; };
void Ov209_Reaction_ChargeThenBreak(int self) {
    int obj = *(int *)(self + 4);
    if (*(unsigned char *)(obj + 0x49) == 0) {
        int acc = *(int *)(obj + 0x2c) + *(int *)(*(int *)self + 0x2c);
        *(int *)(obj + 0x2c) = acc;
        if (acc >= 0x99a) {
            Ov107_BuildAndSendUpdate(*(int *)obj, 0x154, 4, *(int *)(*(int *)obj + 0x3c4) + 4);
            *(unsigned char *)(obj + 0x49) = 1;
        }
    }
    if (*(unsigned char *)(*(int *)(obj + 4) + 0xad) != 0) {
        return;
    }
    *(unsigned short *)(*(int *)obj + 0x1ae) &= ~1;
    ((struct b8 *)(*(int *)(*(int *)obj + 0x3b8) + 8))->f |= 1;
    ((struct b8 *)(*(int *)(*(int *)obj + 0x3b4) + 8))->f |= 1;
    Ov107_PostTagUpdate((Actor *)(*(int *)obj), 6, 1);
    *(int *)(obj + 0x2c) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov209_AiChargeTimeout);
}
