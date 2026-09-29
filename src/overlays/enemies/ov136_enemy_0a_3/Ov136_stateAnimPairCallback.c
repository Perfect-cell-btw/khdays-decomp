/* State step: posts pose 6, sends the two-halfword animation pair from the overlay's table to the
 * actor's event callback (+0x24) and installs the idle step. */

#include "game/enemy_common.h"

extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov136_020d39e4[];
extern void Ov136_stIdlePose7ClearTimerAdvance(void);
void Ov136_stateAnimPairCallback(int *node) {
    int *state = (int *)node[1];
    unsigned short pair[2];
    unsigned short *pp;
    void (*cb)();
    Ov107_PostTagUpdate((Actor *)(*state), 6, 0);
    pp = pair;
    pp[1] = data_ov136_020d39e4[1];
    pp[0] = data_ov136_020d39e4[0];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov136_stIdlePose7ClearTimerAdvance);
}
