/* Charge tick of the ov256 actor: the +0x4c timer accumulates the frame rate and while charges remain
 * (+0x69) one is spent on each of the +0x434 / +0x438 claws (020d1068). Once the partner holds no
 * queued move pose 0x10 plays, +0x54 and the +0x6a flag clear and the node moves on to 020cfafc. */

#include "nitro/types.h"
#include "game/enemy_common.h"

extern void Ov256_FlagDoneAndNotify(int claw);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov256_AiChargeRepeat(void);

void Ov256_ChargeTick(int *node)
{
    int *state = (int *)node[1];

    state[0x13] += *(int *)(node[0] + 0x2c);
    if (*((u8 *)state + 0x69) != 0) {
        *((u8 *)state + 0x69) -= 1;
        Ov256_FlagDoneAndNotify(*(int *)(*state + 0x434));
        Ov256_FlagDoneAndNotify(*(int *)(*state + 0x438));
    }
    if (*(u8 *)(state[1] + 0xad) != 0) {
        return;
    }
    Ov107_PostTagUpdate((Actor *)(*state), 0x10, 0);
    state[0x15] = 0;
    *((u8 *)state + 0x6a) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov256_AiChargeRepeat);
}
