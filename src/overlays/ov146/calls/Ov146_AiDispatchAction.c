/* Ov146_AiDispatchAction -- ov146's move dispatcher.
 *
 * Its reset ADDS 0x40 to the hw60 hi-byte before clearing 0x86 from it, and only drops bit 1 of
 * the halfword at +0x1ae (most of the family clears bits 0-1). Then bit 0 goes on the sub-object
 * at ctx[0]+0x3ac.
 *
 * Case 3 is out of order (after 9) as everywhere else.
 *
 * Form notes (codegen-cracks.md): `hi |= 0x40` has no lsl#0x10/lsr#0x10 trunc pair so it needs the
 * explicit extract/reassemble, while `hi &= ~0x86` has one and takes the bitfield form -- two
 * opposite forms back to back, as in Ov231_Item_AiEnterCharge and Ov252_AiDispatchAction. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov146_HideEntry(void);
extern void Ov146_GrabEntry(void);
extern void Ov146_AiEnterIdle(void);
extern void Ov146_AiEnterApproach(void);
extern void Ov146_AiEnterMount(void);
extern void Ov146_AiEnterDismount(void);
extern void Ov146_ChargeDecide(void);
extern void Ov146_SetPose4ThenAdvanceSlot(void);
extern void Ov146_GuardEntry(void);
extern void Ov146_KnockDownEntry(void);
extern void Ov146_HitEntry(void);
extern void Ov146_AiEnterApproachB(void);

void Ov146_AiDispatchAction(int self) {
    int *ctx;
    unsigned short v;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);

        v = *(unsigned short *)(ctx[0] + 0x60);
        *(unsigned short *)(ctx[0] + 0x60) =
            (unsigned short)((v & ~0xff00)
                             | (((((unsigned int)v << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x86;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~2;
        ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov146_HideEntry);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov146_GrabEntry);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov146_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov146_AiEnterApproach);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov146_AiEnterMount);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov146_AiEnterDismount);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov146_ChargeDecide);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov146_SetPose4ThenAdvanceSlot);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov146_GuardEntry);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov146_KnockDownEntry);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov146_HitEntry);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov146_AiEnterApproachB);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
