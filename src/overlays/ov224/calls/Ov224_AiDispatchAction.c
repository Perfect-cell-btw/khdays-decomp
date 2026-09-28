/* Ov224_AiDispatchAction -- ov221's move dispatcher. Same shape as the ov210/ov228/ov231 ones: -1 at
 * ctx[0]+0x1c7 means nothing queued, the id is copied to +0x1c6 and it is that copy the switch
 * reads, and the slot is cleared on every path.
 *
 * The reset here is the richest of the family. Besides clearing 0xc6 from the hw60 hi-byte and
 * bits 0-1 of the halfword at +0x1ae, it toggles bit 0 on four sub-objects (+0x3b0 cleared,
 * +0x3b4/+0x3b8/+0x3bc set), and the flag at ctx+0x78 gates two of them: it adds 0x40 to the
 * hw60 and flips the sense of the +0x3ac bit. So +0x78 is "the alternate stance is up".
 *
 * Case 7 is absent from the switch -- its jump-table slot points at the default, which is how mwcc
 * fills a gap in an otherwise dense table. The source case order is the body order (13 and 16 sit
 * out of place, and 3 is late as in every other dispatcher).
 *
 * Form notes (codegen-cracks.md): `hi &= ~0xc6` HAS the lsl#0x10/lsr#0x10 trunc pair so it takes
 * the bitfield form, while `hi |= 0x40` does NOT and needs the explicit extract/reassemble; the
 * +8 fields are byte-in-word. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov224_RaiseFlagsAndArmChildren(void);
extern void Ov224_AiEnterWait(void);
extern void Ov224_AiEnterCuedAnim(void);
extern void Ov224_AiEnterRetreat(void);
extern void Ov224_AiEnterRetreatB(void);
extern void Ov224_AiEnterCooldown(void);
extern void Ov224_AiEnterChase(void);
extern void Ov224_EnterAttack(void);
extern void Ov224_AiEnterChargeWindup(void);
extern void Ov224_AiEnterRecoilTurn(void);
extern void Ov224_AiEnterLeap(void);
extern void Ov224_AiEnterAttackB(void);
extern void Ov224_AiEnterCuedAnimB(void);
extern void Ov224_AiLockAndPostUpdate(void);
extern void Ov224_AiEnterHold(void);
extern void Ov224_AiEnterApproach(void);

void Ov224_AiDispatchAction(int self) {
    int *ctx;
    unsigned short v;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;

        if (ctx[0x1e] != 0) {
            v = *(unsigned short *)(ctx[0] + 0x60);
            *(unsigned short *)(ctx[0] + 0x60) =
                (unsigned short)((v & ~0xff00)
                                 | (((((unsigned int)v << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
        }

        ((B8 *)(*(int *)(ctx[0] + 0x3b0) + 8))->f &= ~1;
        ((B8 *)(*(int *)(ctx[0] + 0x3b4) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x3b8) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x3bc) + 8))->f |= 1;

        if (ctx[0x1e] != 0) {
            ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f &= ~1;
        } else {
            ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f |= 1;
        }

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov224_RaiseFlagsAndArmChildren);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov224_AiEnterWait);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov224_AiEnterCuedAnim);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov224_AiEnterRetreat);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov224_AiEnterRetreatB);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov224_AiEnterCooldown);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov224_AiEnterChase);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov224_AiEnterChargeWindup);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov224_AiEnterRecoilTurn);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov224_AiEnterLeap);
            break;
        case 16:
            SetIndexedSlot(self, 1, Ov224_AiEnterAttackB);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov224_EnterAttack);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov224_AiEnterCuedAnimB);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov224_AiLockAndPostUpdate);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov224_AiEnterHold);
            break;
        case 15:
            SetIndexedSlot(self, 1, Ov224_AiEnterApproach);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
