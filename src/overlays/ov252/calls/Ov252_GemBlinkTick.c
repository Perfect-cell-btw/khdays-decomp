/* Blink tick of an ov252 gem: once its +0 part stops animating, the first pass (+0x26 set) clears the
 * flag and fades layers 0, 2, 4 and 1 in (mode 1); afterwards they fade out (mode 2), sound 0x148/0xb
 * plays at the gem's +8 point and the node moves on to 020d3e04. */
extern void SetSubitemState(int obj, int layer, int mode, int arg);
extern void Ov107_BuildAndSendUpdate(int actor, int bank, int variant, void *at);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov252_GemTick(void);

void Ov252_GemBlinkTick(int *node)
{
    int *state = (int *)node[1];

    if (*(unsigned char *)(*state + 0xad) != 0) {
        return;
    }
    if (*((unsigned char *)state + 0x26) == 1) {
        *((unsigned char *)state + 0x26) = 0;
        SetSubitemState(*state, 0, 1, 0);
        SetSubitemState(*state, 2, 1, 0);
        SetSubitemState(*state, 4, 1, 0);
        SetSubitemState(*state, 1, 1, 0);
    } else {
        SetSubitemState(*state, 0, 2, 0);
        SetSubitemState(*state, 2, 2, 0);
        SetSubitemState(*state, 4, 2, 0);
        SetSubitemState(*state, 1, 2, 0);
        Ov107_BuildAndSendUpdate(state[1], 0x148, 0xb, state + 2);
        SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), Ov252_GemTick);
    }
}
