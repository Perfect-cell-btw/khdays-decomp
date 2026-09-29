/* AI-state tick: accumulate the owner's per-frame delta into the node timer at +0x2c.
 * Once it passes 0x198, arm the node once -- set the two speed words at +0x30 and +0x34
 * and the range at +0x1c, then latch the armed flag at +0x41 -- and run the reposition
 * step every tick from then on. Finally, unless the actor's busy byte at +0xad is set,
 * fire attack 5 and hand off to the next state through the indexed dispatcher. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern void Ov128_DecaySpinOverElapsed(int *self);
extern void SetIndexedSlot(int *self, int idx, void *cb);
extern void Ov128_ClearHiFlagAndAdvance(void);

void Ov128_ArmThenAttack(int *self)
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
        Ov128_DecaySpinOverElapsed(self);
    }

    if (((u8 *)node[1])[0xad] != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)node[0], 5, 1);
    SetIndexedSlot(self, *(signed char *)((char *)self + 0x20), &Ov128_ClearHiFlagAndAdvance);
}
