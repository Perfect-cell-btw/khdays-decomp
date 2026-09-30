/* Target check of an ov235 state: the nearest target (020cab14) becomes +0x5c; without one
 * sub-state 2 is requested and the tick ends. Otherwise animation 4 plays, the +0x3a8 part plays
 * motion 3, reaction +0x3c8 (as a halfword) mode 2 fires at the +4 point and the tick hands over to
 * Ov235_GlideTick5. */

#include "game/enemy_common.h"

extern int Ov107_FindNearestObject(int obj, int kind);
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_GlideTick5(int *node);

void Ov235_CheckTarget(int *node)
{
    int *state = (int *)node[1];

    state[0x17] = Ov107_FindNearestObject(*state, 0);
    if (state[0x17] == 0) {
        *(unsigned char *)(*state + 0x1c7) = 2;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3a8), 3, 0);
    Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3c8), 2, (void *)state[1]);
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov235_GlideTick5);
}
