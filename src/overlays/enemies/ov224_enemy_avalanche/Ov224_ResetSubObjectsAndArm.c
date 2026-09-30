/* c634 init: reset owner status bytes (+0x1c6=0, +0x1c7=-1, +0x40c=-1), clear bit0 of the
 * low byte at each of the 5 sub-objects (owner+0x3ac[i]+8), cache the owner's pos pointer
 * (owner+0xb0) into obj[2] and its parent's pos (*(owner+0x3b0)->+0x20) into obj[3], set
 * owner hw60 hi bits 6, then arm the three phase callbacks (slots 1/0/2) via SetIndexedSlot. */
struct b8 { unsigned int b : 8; };
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov224_RaiseFlagsAndArmChildren(void);
extern void Ov224_AiDispatchAction(void);
extern void Ov224_HoverTick(void);
void Ov224_ResetSubObjectsAndArm(int self) {
    int *obj = *(int **)(self + 4);
    int i = 0;
    *(char *)(*obj + 0x1c6) = 0;
    *(char *)(*obj + 0x1c7) = -1;
    *(char *)(*obj + 0x40c) = -1;
    do {
        int e = ((int *)*obj)[i + 0xeb];
        i++;
        ((struct b8 *)(e + 8))->b &= ~1;
    } while (i < 5);
    obj[2] = *obj + 0xb0;
    obj[3] = **(int **)(*obj + 0x3b0) + 0x20;
    {
        unsigned short v = *(unsigned short *)(*obj + 0x60);
        *(unsigned short *)(*obj + 0x60) =
            (unsigned short)((v & ~0xff00) | (((((unsigned int)v << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    }
    SetIndexedSlot(self, 1, &Ov224_RaiseFlagsAndArmChildren);
    SetIndexedSlot(self, 0, &Ov224_AiDispatchAction);
    SetIndexedSlot(self, 2, &Ov224_HoverTick);
}
