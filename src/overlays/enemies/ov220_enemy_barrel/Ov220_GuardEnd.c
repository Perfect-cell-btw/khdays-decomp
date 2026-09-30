/* Guard end of the ov220 enemy: once the +4 item is idle the +0x1c phase advances and the +0x21a
 * stamina is refilled from the +0x218 maximum divided by 2, 3 or 5 (at least 1) according to the
 * phase; then the state ends with sub-state 2. */

#include "nitro/types.h"
#include "game/actor.h"

extern int func_02020400(int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov220_GuardEnd(int *node)
{
    int *state = (int *)node[1];
    Actor *actor;
    int div;

    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    {
        switch (state[7]) {
        case 0:
            state[7]++;
            div = 2;
            break;
        case 1:
            state[7]++;
            div = 3;
            break;
        default:
            state[7]++;
            div = 5;
            break;
        }
        actor = (Actor *)*state;
        actor->hitPoints = func_02020400(actor->hitPointsCap, div);
        actor = (Actor *)*state;
        if (actor->hitPoints <= 0) {
            actor->hitPoints = 1;
        }
    }
    ((Actor *)*state)->nextState = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
