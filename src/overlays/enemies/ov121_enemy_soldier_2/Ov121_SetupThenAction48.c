/* Enter the telegraph: set 0x82 in the hw60 high byte and drop 0x0c from it, raise bit 0 of the
 * flags at +0x1ae, clear bit 0 of the status word at +8 of the component at +0x388, reset the
 * hold timer and fire two events on the anchor at state[3] -- 0x11a with slot 6 and then 0x48.
 *
 * Matched byte-exact 2026-07-23, first compile. One of three byte-identical siblings. */
extern void Ov107_BuildAndSendUpdate(int obj, int a, int b, int c);
extern void SetIndexedSlot(void *node, int idx, void *cb);
extern void Ov121_TimerAcquireTargetAngleThenAdvance(void);

struct hw60 { unsigned short lo : 8, hi : 8; };
struct LowByte32 { unsigned bits : 8; };

void Ov121_SetupThenAction48(int *node) {
    int *state = (int *)node[1];

    {
        unsigned short hw60 = *(unsigned short *)(state[0] + 0x60);
        *(unsigned short *)(state[0] + 0x60) =
            (hw60 & ~0xff00) | (((((unsigned int)hw60 << 0x10) >> 0x18 | 0x82) << 0x18) >> 0x10);
    }
    ((struct hw60 *)(state[0] + 0x60))->hi &= ~0xc;
    *(unsigned short *)(state[0] + 0x1ae) |= 1;
    ((struct LowByte32 *)(*(int *)(state[0] + 0x388) + 8))->bits &= ~1;
    state[0x10] = 0;
    Ov107_BuildAndSendUpdate(state[0], 0x11a, 6, state[3]);
    Ov107_BuildAndSendUpdate(state[0], 0, 0x48, state[3]);
    SetIndexedSlot(node, *(signed char *)((int)node + 0x20), Ov121_TimerAcquireTargetAngleThenAdvance);
}
