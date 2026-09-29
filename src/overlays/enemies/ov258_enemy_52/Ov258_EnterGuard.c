/* Enter the ov258 actor's guard: pose 4 plays, the +0x30 timer clears, +0x50 = 2, the +0x52 and +0x53
 * step countdowns become 0 and 3 with the +0x44 clock cleared, the rig switches (020cd028 mode 1);
 * in moves 7 and 8 the brain continues with 020cf324, otherwise +0x34 / +0x3c clear and it waits on
 * 020cef90. */

#include "nitro/types.h"
#include "game/enemy_common.h"

typedef struct { u8 lo : 4; u8 hi : 4; } NibblePair;

extern void Ov258_AcquireTarget(int *node, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov258_SlamTick(void);
extern void Ov258_GuardTick(void);

void Ov258_EnterGuard(int *node)
{
    int *state = (int *)node[1];

    Ov107_PostTagUpdate((Actor *)(*state), 4, 0);
    state[0xc] = 0;
    *(short *)(state + 0x14) = 2;
    ((NibblePair *)((u8 *)state + 0x52))->lo = 0;
    state[0x11] = 0;
    ((NibblePair *)((u8 *)state + 0x53))->lo = 3;
    Ov258_AcquireTarget(node, 1);
    if (!(*(signed char *)(*state + 0x1c6) != 8 && *(signed char *)(*state + 0x1c6) != 7)) {
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov258_SlamTick);
        return;
    }
    state[0xd] = 0;
    state[0xf] = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov258_GuardTick);
}
