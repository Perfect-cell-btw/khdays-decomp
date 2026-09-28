/* Take-off enter tick of an ov257 state: animation 0x1c plays, the +0x3d0 part plays motion 0x19,
 * bit 6 of the owner's +0x60 high byte is raised, the +0x54 timer and +0x76 clear and the tick
 * hands over to Ov257_JumpStartTick. */

#include "nitro/types.h"

extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_JumpStartTick(int *node);

void Ov257_TakeOffEnterTick(int *node)
{
    int *state = (int *)node[1];
    u16 hw;

    Ov107_PostTagUpdate(*state, 0x1c, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3d0), 0x19, 0);
    hw = *(u16 *)(*state + 0x60);
    *(u16 *)(*state + 0x60) = (hw & ~0xff00) |
        ((((((unsigned int)hw << 0x10) >> 0x18) | 0x40) << 0x18) >> 0x10);
    state[0x15] = 0;
    *((unsigned char *)state + 0x76) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_JumpStartTick);
}
