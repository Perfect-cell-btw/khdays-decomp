/* Wind-up tick of an ov235 state: the +0x54 timer accumulates the owner's rate; past 0x333,
 * once (+0x65), reaction +0x3c8 (as a halfword) mode 0xb fires at the +4 point. Once the +0xc
 * idle byte clears, animation 0x11 plays, the flag clears and the tick hands over to
 * Ov235_StrikeTick. */
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov235_StrikeTick(int *node);

void func_ov235_020cf664(int *node)
{
    int *state = (int *)node[1];

    state[0x15] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x65) == 0 && state[0x15] >= 0x333) {
        Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3c8), 0xb, (void *)state[1]);
        *((unsigned char *)state + 0x65) = 1;
    }
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0x11, 0);
    *((unsigned char *)state + 0x65) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov235_StrikeTick);
}
