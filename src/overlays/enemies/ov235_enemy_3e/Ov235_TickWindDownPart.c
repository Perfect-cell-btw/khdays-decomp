/* Wind-down tick of an ov235 part: the +8 timer accumulates the owner's rate; at 0.75 animation
 * channels 0, 2, 4 and 1 are stopped (0203b9fc mode 2), the timer clears and the tick hands over to
 * Ov235_FinishAfterDelay. */
extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_FinishAfterDelay(int *node);

void Ov235_TickWindDownPart(int *node)
{
    int *state = (int *)node[1];

    state[2] += *(int *)(*node + 0x2c);
    if (!(state[2] < 0xc00)) {
        SetSubitemState(*state, 0, 2, 0);
        SetSubitemState(*state, 2, 2, 0);
        SetSubitemState(*state, 4, 2, 0);
        SetSubitemState(*state, 1, 2, 0);
        state[2] = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov235_FinishAfterDelay);
        return;
    }
}
