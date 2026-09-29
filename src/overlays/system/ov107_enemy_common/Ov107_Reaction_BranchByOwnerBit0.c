/* c634 reaction handler: branch on owner->+0x40 bit 0 — dispatch state with the
 * Ov107_SoundFollowTick callback when set, else the Ov107_SoundRestartTick callback.
 * self->+0x20 (signed) = slot index. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(int self, int index, void *cb);
struct sbit0 { int b:1; };
void Ov107_Reaction_BranchByOwnerBit0(int self) {
    int owner = *(int *)*(int *)(self + 4);
    if (((struct sbit0 *)(owner + 0x40))->b) {
        SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov107_SoundFollowTick);
    } else {
        SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov107_SoundRestartTick);
    }
}
