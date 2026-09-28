/* Charge tick of the ov146 actor: +0x3c accumulates the frame rate; stage 0 (+0x50) starts the +0x3bc
 * effect after 1.33, stage 1 plays sound 0x125/5 at the +0xc point after 2.76; afterwards, once the
 * partner holds no queued move, bit 0 of +0x1ae clears, the next move is 2 and the node ends. */
typedef unsigned short u16;

extern int Ov146_Mount_SetStateIfReady(int param_1, int param_2);
extern void Ov107_BuildAndSendUpdate(int actor, int bank, int variant, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);

void Ov146_ChargeTick(int *node)
{
    int *state = (int *)node[1];

    state[0xf] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x50) == 0) {
        if (state[0xf] < 0x1540) {
            return;
        }
        Ov146_Mount_SetStateIfReady(*(int *)(*state + 0x3bc), 1);
        *((unsigned char *)state + 0x50) += 1;
        return;
    }
    if (*((unsigned char *)state + 0x50) == 1) {
        if (state[0xf] < 0x2c18) {
            return;
        }
        Ov107_BuildAndSendUpdate(*state, 0x125, 5, (void *)state[3]);
        *((unsigned char *)state + 0x50) += 1;
        return;
    }
    if (*(unsigned char *)(state[1] + 0xad) != 0) {
        return;
    }
    *(u16 *)(*state + 0x1ae) &= ~1;
    *(unsigned char *)(*state + 0x1c7) = 2;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), 0);
}
