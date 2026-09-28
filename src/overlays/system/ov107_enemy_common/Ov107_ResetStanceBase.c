/* Actor +0x1f8 handler: clears the pending action, sets stance bits 0x82, clears bit 0 and resets
 * +0x2e8 to 0x800. */

#include "nitro/types.h"
#include "game/actor.h"

void Ov107_ResetStanceBase(Actor *self)
{
    u16 hw;

    self->nextState = 0;

    hw = self->flags60.raw;
    self->flags60.raw = (hw & ~0xff00) |
        (((((u32)hw << 0x10) >> 0x18) | 0x82) << 0x18 >> 0x10);

    hw = self->flags60.raw;
    self->flags60.raw = (hw & ~0xff00) |
        (((u32)(u16)((((u32)hw << 0x10) >> 0x18) & ~1) << 0x18) >> 0x10);

    self->field_2e8 = 0x800;
}
