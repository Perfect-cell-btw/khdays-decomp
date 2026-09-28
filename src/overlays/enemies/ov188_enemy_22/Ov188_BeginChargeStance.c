/* Enter the charge stance: set 0x06 and then, after the sub-object is disarmed, 0x40 in the
 * hw60 high byte; raise bit 0 of the flags at +0x1ae, clear bit 0 of the status word at +8 of
 * the component at +0x388, start effect 0x49 anchored on the object's own transform and reset
 * the travel accumulator.
 *
 * Matched byte-exact 2026-07-23, first compile. Both hw60 ORs are the explicit shift
 * expression: the `hi |= K` bitfield form adds a 16-bit truncation the ROM does not have.
 *
 * One of four byte-identical siblings. */
extern void Ov107_BuildAndSendUpdate(int obj, int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov188_TimerGateHw60FlipThenAdvance(void);

struct LowByte32 { unsigned bits : 8; };

void Ov188_BeginChargeStance(int *node) {
    int *state = (int *)node[1];

    {
        unsigned short hw60 = *(unsigned short *)(state[0] + 0x60);
        *(unsigned short *)(state[0] + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 6) << 0x18) >> 0x10);
    }
    *(unsigned short *)(state[0] + 0x1ae) |= 1;
    ((struct LowByte32 *)(*(int *)(state[0] + 0x388) + 8))->bits &= ~1;
    {
        unsigned short hw60 = *(unsigned short *)(state[0] + 0x60);
        *(unsigned short *)(state[0] + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10);
    }
    Ov107_BuildAndSendUpdate(state[0], 0, 0x49, state[0] + 0x74);
    state[6] = 0;
    SetIndexedSlot(node, *(signed char *)((int)node + 0x20), Ov188_TimerGateHw60FlipThenAdvance);
}
