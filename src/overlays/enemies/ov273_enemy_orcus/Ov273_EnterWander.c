/* Wander entry: sets obj->+0x48 = self->f0->f2c*30/10 and, unless *(obj->+8) is set, plays
 * pose 2 (looping), picks a random turn direction (+0x18 = -1 or +1), clears the +0x1c timer
 * and dispatches to 020cdb1c. */

#include "game/engine.h"

extern void Ov107_PostTagUpdate(int owner, int a, int b);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov273_CircleStrafeTick(void);
void Ov273_EnterWander(int self) {
    int obj = *(int *)(self + 4);
    int v;
    *(int *)(obj + 0x48) = *(int *)(*(int *)self + 0x2c) * 30 / 10;
    if (*(unsigned char *)(*(int *)(obj + 8)) != 0) {
        return;
    }
    Ov107_PostTagUpdate(*(int *)obj, 2, 1);
    /* +(v-v) forces `adds r0,r0,#0` (rand result copied+tested); +0 would fold away */
    *(int *)(obj + 0x18) = (RandNextScaled(2) + (v - v)) != 0 ? -1 : 1;
    *(int *)(obj + 0x1c) = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov273_CircleStrafeTick);
}
