/* Play anim 7, send the cue at data_ov277_020d36bc entry 9 through the actor's +0x24 hook,
 * clear the low nibble of the actor's +0x420 word, the +0x1c word and the +9 byte, then
 * dispatch to 020d04b4. */
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern void SetIndexedSlot(void *obj, int idx, void *value);
extern unsigned short data_ov277_020d36bc[];
extern void Ov277_SummonWindupTick(void);

void Ov277_EnterAnim7(int *node) {
    int *state = (int *)node[1];
    unsigned short pair[2];
    unsigned short *pp;
    void (*cb)();

    Ov107_PostTagUpdate(*state, 7, 0);
    pp = pair;
    pp[1] = data_ov277_020d36bc[19];
    pp[0] = data_ov277_020d36bc[18];
    cb = *(void (**)())(*state + 0x24);
    if (cb != 0) cb(*state, pp, 4);
    *(int *)(*state + 0x420) &= ~0xf;
    state[7] = 0;
    *((unsigned char *)state + 9) = 0;
    SetIndexedSlot(node, *(signed char *)(node + 8), Ov277_SummonWindupTick);
}
