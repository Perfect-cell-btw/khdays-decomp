/* Strike tick of an ov255 state: the +0x50 timer accumulates the owner's rate; past 1.57, once
 * (+0x65), reaction +0x3f8 (as a halfword) mode 0xc fires at the +4 point. Once the +0xc idle byte
 * clears, animation 0x12 plays, the +0x3a4 part plays motion 0xf, +0x63, the +0x44 timer, the
 * flag and +0x62 clear and the tick hands over to Ov255_SlamTick. */
extern void Ov107_BuildAndSendUpdate(int owner, int id, int mode, void *at);
extern void Ov107_PostTagUpdate(int owner, int anim, int mode);
extern void Ov107_StartAnim(int part, int motion, int mode);
extern void SetIndexedSlot(int *node, int slot, void *cb);
extern void Ov255_SlamTick(int *node);

void Ov255_StrikeTick(int *node)
{
    int *state = (int *)node[1];

    state[0x14] += *(int *)(node[0] + 0x2c);
    if (*((unsigned char *)state + 0x65) == 0 && state[0x14] >= 0x1911) {
        Ov107_BuildAndSendUpdate(state[0], (short)*(int *)(*state + 0x3f8), 0xc, (void *)state[1]);
        *((unsigned char *)state + 0x65) = 1;
    }
    if (*(unsigned char *)state[3] != 0) {
        return;
    }
    Ov107_PostTagUpdate(*state, 0x12, 0);
    Ov107_StartAnim(*(int *)(*state + 0x3a4), 0xf, 0);
    *((unsigned char *)state + 0x63) = 0;
    state[0x11] = 0;
    *((unsigned char *)state + 0x65) = 0;
    *((unsigned char *)state + 0x62) = 0;
    SetIndexedSlot(node, *(signed char *)((char *)node + 0x20), (void *)Ov255_SlamTick);
}
