/* Ov227_AiDispatchAction -- ov227's move dispatcher. The ov221/ov225 shape, and the three of them
 * differ only in the tail of the reset:
 *   ov221 -- the +0x3ac bit is CONDITIONAL on ctx+0x78 (set when the flag is clear, cleared when
 *            it is set);
 *   ov225 -- +0x3ac is set unconditionally, and +0x3b0 is then set again after being cleared;
 *   ov227 -- +0x3ac is set unconditionally and that is the end of it (this one).
 * Case 7 is absent from the switch, as in ov221; ov225 has it.
 *
 * ctx+0x78 -- the alternate stance -- still gates the extra 0x40 on the hw60.
 *
 * Form notes (codegen-cracks.md): `hi &= ~0xc6` has the lsl#0x10/lsr#0x10 trunc pair so it takes
 * the bitfield form, `hi |= 0x40` does not and needs the explicit extract/reassemble, and the +8
 * fields are byte-in-word. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov227_RaiseFlagsAndArmChildren(void);
extern void Ov227_AiEnterWait(void);
extern void Ov227_AiEnterCuedAnim(void);
extern void Ov227_AiEnterRetreat(void);
extern void Ov227_AiEnterRetreatB(void);
extern void Ov227_AiEnterCooldown(void);
extern void Ov227_AiEnterChase(void);
extern void Ov227_AiEnterAnim24IfTarget(void);
extern void Ov227_AiEnterChargeWindup(void);
extern void Ov227_AiEnterRecoilTurn(void);
extern void Ov227_AiEnterLeap(void);
extern void Ov227_AiEnterAttackB(void);
extern void Ov227_AiEnterCuedAnimB(void);
extern void Ov227_AiLockAndPostUpdate(void);
extern void Ov227_AiEnterHold(void);
extern void Ov227_AiEnterApproach(void);

void Ov227_AiDispatchAction(int self) {
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
        ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov227_RaiseFlagsAndArmChildren);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov227_AiEnterWait);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov227_AiEnterCuedAnim);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov227_AiEnterRetreat);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov227_AiEnterRetreatB);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov227_AiEnterCooldown);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov227_AiEnterChase);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov227_AiEnterChargeWindup);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov227_AiEnterRecoilTurn);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov227_AiEnterLeap);
            break;
        case 16:
            SetIndexedSlot(self, 1, Ov227_AiEnterAttackB);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov227_AiEnterAnim24IfTarget);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov227_AiEnterCuedAnimB);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov227_AiLockAndPostUpdate);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov227_AiEnterHold);
            break;
        case 15:
            SetIndexedSlot(self, 1, Ov227_AiEnterApproach);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
