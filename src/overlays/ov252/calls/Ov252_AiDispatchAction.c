/* Ov252_AiDispatchAction -- ov252's move dispatcher.
 *
 * Two small departures from the family: the hw60 gets 0x14 ADDED before 0x8a is cleared (most of
 * the others only clear), and the id is copied from +0x1c7 to +0x1c6 AFTER the flag work rather
 * than before it. Neither changes what the switch reads, but both are visible in the order.
 *
 * Cases 1 and 9 are absent from the switch; case 3 is out of order (after 11) as everywhere else.
 *
 * Form notes (codegen-cracks.md): `hi |= 0x14` has no lsl#0x10/lsr#0x10 trunc pair so it needs the
 * explicit extract/reassemble, while `hi &= ~0x8a` has one and takes the bitfield form. Two
 * opposite forms, back to back, in one function -- as in Ov231_Item_AiEnterCharge. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov252_CollapseEntry(void);
extern void Ov252_AiEnterIdleArmed(void);
extern void Ov252_RetreatDecision(void);
extern void Ov252_ChargeEntry(void);
extern void Ov252_AiEnterIdleReset(void);
extern void Ov252_ShedPieceEntry(void);
extern void Ov252_AiTurnAroundAnim13(void);
extern void Ov252_LiftEntry(void);
extern void Ov252_PartHoverEntry(void);
extern void Ov252_AiEnterIdleWithCharge(void);
extern void Ov252_PartDescendEntry(void);
extern void Ov252_DriftTick(void);
extern void Ov252_ShedEntry(void);

void Ov252_AiDispatchAction(int self) {
    int *ctx;
    unsigned short v;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        v = *(unsigned short *)(ctx[0] + 0x60);
        *(unsigned short *)(ctx[0] + 0x60) =
            (unsigned short)((v & ~0xff00)
                             | (((((unsigned int)v << 0x10) >> 0x18 | 0x14) << 0x18) >> 0x10));
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x8a;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov252_CollapseEntry);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov252_AiEnterIdleArmed);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov252_RetreatDecision);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov252_ChargeEntry);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov252_ShedPieceEntry);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov252_AiTurnAroundAnim13);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov252_LiftEntry);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov252_PartDescendEntry);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov252_PartHoverEntry);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov252_ShedEntry);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov252_DriftTick);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov252_AiEnterIdleWithCharge);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov252_AiEnterIdleReset);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
