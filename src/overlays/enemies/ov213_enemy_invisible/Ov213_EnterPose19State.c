/* State entry: sends message data_ov213_020d2e6c (4 bytes) to the actor's +0x24 hook when set,
 * clears the +0x69 latch, plays pose 0x19, zeroes the +0x1c timer, the +0x6a byte and the +0x70
 * word, then moves the node to 020d0020. */

#include "game/enemy_common.h"

struct hpair { unsigned short a, b; };

extern void SetIndexedSlot(int *node, int slot, void *cb);
extern const struct hpair data_ov213_020d2e6c;
extern void Ov213_TailSweepTick(void);

void Ov213_EnterPose19State(int *node) {
    int *state = (int *)node[1];
    struct hpair msg = data_ov213_020d2e6c;
    void (*hook)(int, struct hpair *, int) = *(void (**)(int, struct hpair *, int))(*state + 0x24);

    if (hook != 0) {
        hook(*state, &msg, 4);
    }
    *((unsigned char *)state + 0x69) = 0;
    Ov107_PostTagUpdate((Actor *)(*state), 0x19, 0);
    state[7] = 0;
    *((unsigned char *)state + 0x6a) = 0;
    state[0x1c] = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov213_TailSweepTick);
}
