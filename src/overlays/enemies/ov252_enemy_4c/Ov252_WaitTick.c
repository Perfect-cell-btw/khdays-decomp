/* Wait tick of the ov252 actor: the +0x64 timer accumulates the frame rate; once the partner holds no
 * queued move, after 5.0 the next move is 0xa when the target is within 16.0 (020cdfe8) else 0xd and
 * the node ends; before that pose 0 restarts. */

#include "game/enemy_common.h"

extern int Ov252_CheckTarget(int *node, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov252_WaitTick(int *node)
{
    int *state = (int *)node[1];

    state[0x19] += *(int *)(node[0] + 0x2c);
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    if (state[0x19] >= 0x5000) {
        if (Ov252_CheckTarget(node, 0, 0) < 0x10000) {
            *(signed char *)(*state + 0x1c7) = 0xa;
        } else {
            *(signed char *)(*state + 0x1c7) = 0xd;
        }
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0, 0);
}
