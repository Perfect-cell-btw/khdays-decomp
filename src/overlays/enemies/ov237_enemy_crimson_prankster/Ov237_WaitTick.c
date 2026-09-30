/* Wait tick of the ov237 actor: once the +4 rig is idle, a free linked partner (+0x4ac set, its
 * +0x4b0 clear) or a pending +0x4a8 request clears the request and ends the move: 020cd8c8 decides
 * (else the next move is 4); otherwise pose 0 plays. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern int Ov237_PickMove(int *node);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov237_WaitTick(int *node)
{
    int *state = (int *)node[1];
    int free = 0;
    char *actor = (char *)*state;

    if (*(int *)(actor + 0x4ac) != 0 && *(int *)(*(int *)(actor + 0x4a4) + 0x4b0) == 0) {
        free = 1;
    }
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    if (free != 0 || (free == 0 && *(int *)(actor + 0x4a8) != 0)) {
        *(int *)(actor + 0x4a8) = 0;
        if (Ov237_PickMove(node) != 0) {
            SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
            return;
        }
        *(signed char *)(*state + 0x1c7) = 4;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
        return;
    }
    Ov107_PostTagUpdate((Actor *)actor, 0, 0);
}
