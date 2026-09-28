/* Ov225_AiDispatchAction -- ov225's move dispatcher. Same family shape as Ov221_AiDispatchAction (test
 * ctx[0]+0x1c7 against -1, reset, copy the id to +0x1c6, dense jump table of c634 entries, clear
 * the slot); it differs only in the reset and in having a case 7, which ov221 lacks.
 *
 * The flag at ctx+0x78 -- "the alternate stance is up" -- still gates the extra 0x40 on the hw60.
 *
 * ★ Bit 0 of the sub-object at ctx[0]+0x3b0 is CLEARED near the top and SET again at the bottom.
 * That is redundant and it is what the ROM does; ov221 clears it and leaves it. Do not tidy it
 * away -- the second write is a real instruction sequence in the original.
 *
 * Form notes (codegen-cracks.md): `hi &= ~0xc6` has the lsl#0x10/lsr#0x10 trunc pair so it takes
 * the bitfield form, while `hi |= 0x40` does not and needs the explicit extract/reassemble; the
 * +8 fields are byte-in-word. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov225_RaiseFlagsAndArmChildren(void);
extern void Ov225_AiEnterWait(void);
extern void Ov225_AiEnterCuedAnim(void);
extern void Ov225_AiEnterRetreat(void);
extern void Ov225_AiEnterRetreatB(void);
extern void Ov225_AiEnterCooldown(void);
extern void Ov225_AiEnterChase(void);
extern void Ov225_EnterSlam(void);
extern void Ov225_EnterAttack(void);
extern void Ov225_AiEnterChargeWindup(void);
extern void Ov225_AiEnterRecoilTurn(void);
extern void Ov225_AiEnterLeap(void);
extern void Ov225_AiEnterAttackB(void);
extern void Ov225_AiEnterCuedAnimB(void);
extern void Ov225_AiLockAndPostUpdate(void);
extern void Ov225_AiEnterHold(void);
extern void Ov225_AiEnterApproach(void);

void Ov225_AiDispatchAction(int self) {
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
        ((B8 *)(*(int *)(ctx[0] + 0x3b0) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov225_RaiseFlagsAndArmChildren);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov225_AiEnterWait);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov225_AiEnterCuedAnim);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov225_AiEnterRetreat);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov225_AiEnterRetreatB);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov225_AiEnterCooldown);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov225_AiEnterChase);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov225_EnterSlam);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov225_AiEnterChargeWindup);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov225_AiEnterRecoilTurn);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov225_AiEnterLeap);
            break;
        case 16:
            SetIndexedSlot(self, 1, Ov225_AiEnterAttackB);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov225_EnterAttack);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov225_AiEnterCuedAnimB);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov225_AiLockAndPostUpdate);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov225_AiEnterHold);
            break;
        case 15:
            SetIndexedSlot(self, 1, Ov225_AiEnterApproach);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
