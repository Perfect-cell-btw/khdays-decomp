/* Run entry: the +0x80 / +0x10 / +0x44 counters clear, the +0x50 start takes the +8 track's +4
 * position and +0x54 the distance to the end (020cd840); the actor plays pose 4 (move 5) or 1 and
 * its +0x430 part motion 3 or 0; in move 5 the +0x460 / +0x464 helpers are started too. The +0x70
 * flag clears and the node moves to 020cfcac. */

#include "nitro/types.h"

extern int Ov254_PanelYForPhase(int *state, int a);
extern void Ov107_PostTagUpdate(int actor, int pose, int flag);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void Ov254_ForwardToAiTaskWhenReady(int helper, int mode);
extern void Ov254_ForwardToAiIfReady_8(int helper);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov254_GlideTick(void);

void Ov254_RunEntry(int *node)
{
    int *state = (int *)node[1];

    state[0x20] = 0;
    state[4] = 0;
    state[0x11] = 0;
    state[0x14] = *(int *)(state[2] + 4);
    state[0x15] = Ov254_PanelYForPhase(state, -1) - state[0x14];
    Ov107_PostTagUpdate(*state, *(signed char *)(*state + 0x100 + 0xc6) == 5 ? 4 : 1, 0);
    Ov107_StartAnim(*(int *)(*state + 0x430), *(signed char *)(*state + 0x100 + 0xc6) == 5 ? 3 : 0, 0);
    if (*(signed char *)(*state + 0x100 + 0xc6) == 5) {
        Ov254_ForwardToAiTaskWhenReady(*(int *)(*state + 0x460), 3);
        Ov254_ForwardToAiIfReady_8(*(int *)(*state + 0x464));
    }
    *((u8 *)state + 0x70) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov254_GlideTick);
}
