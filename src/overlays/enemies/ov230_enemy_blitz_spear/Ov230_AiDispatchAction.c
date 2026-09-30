/* Ov230_AiDispatchAction -- ov230's move dispatcher. The plain family shape: -1 at ctx[0]+0x1c7 means
 * nothing queued, the id is copied to +0x1c6 and it is that copy the switch reads, and the slot is
 * cleared on every path.
 *
 * The reset drops 0xc6 from the hw60 hi-byte and bits 0-1 of the halfword at +0x1ae, then sets bit
 * 0 on the sub-object at ctx[0]+0x3ac.
 *
 * Case 11 is absent from the switch, and case 3 is out of order (after 10) as everywhere else.
 *
 * The hw60 write HAS the lsl#0x10/lsr#0x10 trunc pair -> bitfield form; the +8 field is
 * byte-in-word. See codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov230_stSetFlags86Clear3ac(void);
extern void Ov230_SetChargeFlagsAndDispatch(void);
extern void Ov230_AiEnterIdle(void);
extern void Ov230_RerollTimerThenDispatchSlot5c(void);
extern void Ov230_GrabRelease(void);
extern void Ov230_PushOffsetTwiceAndReset(void);
extern void Ov230_AiEnterCharge(void);
extern void Ov230_PushConstThenOffset(void);
extern void Ov230_Burst(void);
extern void Ov230_AiEnterRecoilWindup(void);
extern void Ov230_AiLockAndPostUpdate(void);
extern void Ov230_AiEnterHold(void);
extern void Ov230_AiEnterApproach(void);

void Ov230_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov230_stSetFlags86Clear3ac);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov230_SetChargeFlagsAndDispatch);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov230_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov230_RerollTimerThenDispatchSlot5c);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov230_GrabRelease);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov230_PushOffsetTwiceAndReset);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov230_AiEnterCharge);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov230_PushConstThenOffset);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov230_Burst);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov230_AiEnterRecoilWindup);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov230_AiLockAndPostUpdate);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov230_AiEnterHold);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov230_AiEnterApproach);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
