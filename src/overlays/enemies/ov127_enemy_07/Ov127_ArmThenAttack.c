/* AI-state tick: accumulate the owner's per-frame delta into the node timer at +0x2c.
 * Once it passes 0x198, arm the node once -- set the two speed words at +0x30 and +0x34
 * and the range at +0x1c, then latch the armed flag at +0x41 -- and run the reposition
 * step every tick from then on. Finally, unless the actor's busy byte at +0xad is set,
 * fire attack 5 and hand off to the next state through the indexed dispatcher. */
#include "nitro/types.h"

extern void Ov127_DecaySpinOverElapsed(int *self);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov127_ClearHiFlagAndAdvance(void);

void Ov127_ArmThenAttack(int *self)
{
    int *node = (int *)self[1];
    int sum;

    sum = node[0xb] + ((int *)self[0])[0xb];
    node[0xb] = sum;
    if (sum >= 0x198) {
        if (((u8 *)node)[0x41] == 0) {
            node[0xc] = 0x800;
            node[7] = node[0xd] = 0x400;
            ((u8 *)node)[0x41] = 1;
        }
        Ov127_DecaySpinOverElapsed(self);
    }

    if (((u8 *)node[1])[0xad] != 0) {
        return;
    }
    Ov107_PostTagUpdate(node[0], 5, 1);
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), &Ov127_ClearHiFlagAndAdvance);
}
