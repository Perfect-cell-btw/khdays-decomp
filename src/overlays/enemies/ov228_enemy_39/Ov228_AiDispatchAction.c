/* Ov228_AiDispatchAction -- the move dispatcher: play whatever move was queued at ctx[0]+0x1c7, then
 * clear the slot. This is the hub the whole ov228 state machine funnels through; the choosers
 * (Ov228_AiPickMoveByRange, ...) park a move id here and this turns it into a c634 entry.
 *
 * -1 means nothing queued and the whole body is skipped -- but the slot is cleared either way,
 * which is why the early exit lands on the same store.
 *
 * Before dispatching, the id is copied to +0x1c6 (that copy, not the original, is what the switch
 * reads), the hw60 hi-byte is cleared of 0xc6, the halfword at +0x1ae drops bits 0-1, and bit 0
 * of the byte field at *(ctx[0]+0x3ac)+8 is set.
 *
 * The cases are dense 0..13, so mwcc builds a real jump table (`addls pc,pc,r1,lsl #2`). Case 3
 * is written out of order -- after case 11 -- because that is the block layout the ROM has; the
 * table is index-ordered but the blocks follow source order, so the position of case 3 is
 * observable. Do not tidy it into numeric order.
 *
 * The hw60 write HAS the `lsl#0x10 ; lsr#0x10` trunc pair, so it takes the bitfield form (see
 * codegen-cracks.md); the field at +8 is a byte-in-word, so it takes the `unsigned f : 8` form. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov228_stSetFlags86Clear3ac(void);
extern void Ov228_SetChargeFlagsAndDispatch(void);
extern void Ov228_AiEnterIdle(void);
extern void Ov228_RerollTimerThenDispatchSlot5c(void);
extern void Ov228_GrabRelease(void);
extern void Ov228_PushOffsetTwiceAndReset(void);
extern void Ov228_AiEnterCharge(void);
extern void Ov228_PushConstThenOffset(void);
extern void Ov228_Burst(void);
extern void Ov228_AiEnterRecoilWindup(void);
extern void Ov228_AiEnterEmitRing(void);
extern void Ov228_AiLockAndPostUpdate(void);
extern void Ov228_AiEnterHold(void);
extern void Ov228_AiEnterApproach(void);

void Ov228_AiDispatchAction(int self) {
    int *ctx;
    int move;

    ctx = *(int **)(self + 4);
    move = *(signed char *)(ctx[0] + 0x1c7);
    if (move != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = move;
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov228_stSetFlags86Clear3ac);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov228_SetChargeFlagsAndDispatch);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov228_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov228_RerollTimerThenDispatchSlot5c);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov228_GrabRelease);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov228_PushOffsetTwiceAndReset);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov228_AiEnterCharge);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov228_PushConstThenOffset);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov228_Burst);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov228_AiEnterRecoilWindup);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov228_AiEnterEmitRing);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov228_AiLockAndPostUpdate);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov228_AiEnterHold);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov228_AiEnterApproach);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
