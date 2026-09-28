/* c634 handler: set owner hw60 hi bit 0x40, arm Ov230_startAnim(owner,0), then set hi
 * bits 0x80 and 0xe, set bit0 of owner+0x1ae, clear bit0 of the low byte at *(owner+0x3ac)+8,
 * clear obj[0x13], and dispatch into Ov230_PushLocalOffsetToOwner. */
extern void Ov230_startAnim(int owner, int a);
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov230_PushLocalOffsetToOwner(void);
struct b8 { unsigned int b:8; };
static inline void hw60_or(int base, unsigned int k) {
    unsigned short v = *(unsigned short *)(base + 0x60);
    *(unsigned short *)(base + 0x60) =
        (unsigned short)((v & ~0xff00) | (((((unsigned int)v << 0x10) >> 0x18 | k) << 0x18) >> 0x10));
}
void Ov230_SetChargeFlagsAndDispatch(int self) {
    int *obj = *(int **)(self + 4);
    hw60_or(*obj, 0x40);
    Ov230_startAnim(*obj, 0);
    hw60_or(*obj, 0x80);
    hw60_or(*obj, 0xe);
    *(unsigned short *)(*obj + 0x1ae) |= 1;
    ((struct b8 *)(*(int *)(*obj + 0x3ac) + 8))->b &= ~1;
    obj[0x13] = 0;
    SetIndexedSlot(self, *(signed char *)(self + 0x20), &Ov230_PushLocalOffsetToOwner);
}
