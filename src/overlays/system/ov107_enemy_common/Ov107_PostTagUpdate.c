/* Posts a pose change to an active actor: records the pose and flag, marks it pending and calls its
 * pose hook. */

#include "nitro/types.h"
#include "game/actor.h"

void Ov107_PostTagUpdate(Actor *self, int mode, int flag)
{
    if (self->mode != 1)
        return;

    self->mode310 = (u8)mode;
    self->flags311.bits.bit0 = flag;
    self->flags311.head.rest = 3;

    if (self->pfnPlayAnim != 0)
        ((void (*)(Actor *, int, int))self->pfnPlayAnim)(self, mode, flag);
}
