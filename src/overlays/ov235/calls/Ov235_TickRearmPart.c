/* Re-arm tick of an ov235 part: once its rig is idle (+0xad), animation channels 0, 2, 4 and 1 are
 * restarted looped (0203b9fc), the +8 target clears and the tick hands over to
 * Ov235_TickWindDownPart. */
extern void SetSubitemState(int obj, int channel, int a, int b);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_TickWindDownPart(int *node);

void Ov235_TickRearmPart(int *node)
{
    int *state = (int *)node[1];

    if (*(unsigned char *)(*state + 0xad) == 0) {
        SetSubitemState(*state, 0, 1, 1);
        SetSubitemState(*state, 2, 1, 1);
        SetSubitemState(*state, 4, 1, 1);
        SetSubitemState(*state, 1, 1, 1);
        state[2] = 0;
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov235_TickWindDownPart);
        return;
    }
}
