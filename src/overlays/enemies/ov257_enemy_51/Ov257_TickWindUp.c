/* Wind-up tick of an ov257 part: the +0xc timer accumulates the owner's rate. Once it passes 1.0
 * the +4 child's channels 0, 2, 4 and 1 are reset (0203b9fc mode 0) and the child is shown (bit 1
 * of +0x5c cleared), once (+0x10 latch). When the +0 part's +0xad busy byte is clear its channels
 * 0, 2, 4 and 1 are started (mode 1, 1), the timer clears and the tick hands over to
 * Ov257_TickRampUpPart. */
extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov257_TickRampUpPart(int *node);

void Ov257_TickWindUp(int *node)
{
    int *state = (int *)node[1];

    state[3] += *(int *)(*node + 0x2c);
    if (*(unsigned char *)(state + 4) == 0 && state[3] >= 0x1000) {
        SetSubitemState(state[1], 0, 0, 0);
        SetSubitemState(state[1], 2, 0, 0);
        SetSubitemState(state[1], 4, 0, 0);
        SetSubitemState(state[1], 1, 0, 0);
        *(unsigned int *)(state[1] + 0x5c) &= ~2;
        *(unsigned char *)(state + 4) = 1;
    }
    if (*(unsigned char *)(state[0] + 0xad) == 0) {
        SetSubitemState(state[0], 0, 1, 1);
        SetSubitemState(state[0], 2, 1, 1);
        SetSubitemState(state[0], 4, 1, 1);
        SetSubitemState(state[0], 1, 1, 1);
        state[3] = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov257_TickRampUpPart);
        return;
    }
}
