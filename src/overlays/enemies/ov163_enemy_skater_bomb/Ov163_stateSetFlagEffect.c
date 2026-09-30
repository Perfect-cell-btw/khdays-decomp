/* State step: sets bit 0x40 in the high byte of the actor's flags (+0x60), starts the action
 * resource's animation, posts pose 4 and installs the offset-tracking step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern void Ov163_AiTrackOffsetTick(void);
void Ov163_stateSetFlagEffect(int *node) {
    int *state = (int *)node[1];
    {
        unsigned short *p = (unsigned short *)(*state + 0x60);
        unsigned int u = *p;
        *p = (unsigned short)((u & ~0xff00) | ((((u << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    }
    Ov107_StartAnim(*(int *)(*state + 0x3c8), 0, 0);
    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov163_AiTrackOffsetTick);
}
