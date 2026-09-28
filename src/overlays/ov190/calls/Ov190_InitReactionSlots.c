/* All four forms from codegen-cracks.md: the -1 at +0x1c7 is a SIGNED char store, the
 * `&= ~1` at +8 is a byte BITFIELD, and the hw60 `hi |= 6` takes the EXPLICIT form. */
typedef struct { unsigned int lo : 8, rest : 24; } Byte8;
extern void SetIndexedSlot(int self, int index, void *cb);
extern void Ov190_stateSetFlagsClearBit(void);
extern void Ov190_DispatchSubStateByte(void);
extern void Ov190_AiApplyHeadingAndNormal(void);

void Ov190_InitReactionSlots(int self) {
    int *obj = *(int **)(self + 4);
    unsigned short w;

    *(signed char *)(*obj + 0x1c6) = 0;
    *(signed char *)(*obj + 0x1c7) = -1;
    ((Byte8 *)(*(int *)(*obj + 0x388) + 8))->lo &= ~1;
    obj[3] = *obj + 0xb0;
    w = *(unsigned short *)(*obj + 0x60);
    *(unsigned short *)(*obj + 0x60) =
        (unsigned short)((w & ~0xff00)
                         | (((((unsigned int)w << 0x10) >> 0x18 | 6) << 0x18) >> 0x10));
    SetIndexedSlot(self, 1, &Ov190_stateSetFlagsClearBit);
    SetIndexedSlot(self, 0, &Ov190_DispatchSubStateByte);
    SetIndexedSlot(self, 2, &Ov190_AiApplyHeadingAndNormal);
}
