/* Ov245_Rider_AiDispatchAction -- ov238's move dispatcher. The plain family shape: -1 at ctx[0]+0x1c7 means
 * nothing queued, the id is copied to +0x1c6 and it is that copy the switch reads, and the slot is
 * cleared on every path.
 *
 * The reset drops 0xce from the hw60 hi-byte and bit 0 of the halfword at +0x1ae, then sets bit
 * 0 on the sub-object at ctx[0]+0x388.
 *
 * Case 3 is out of order (after 8) as everywhere else.
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
extern void Ov245_EnterBlockPose(void);
extern void Ov245_CrashEnter(void);
extern void Ov245_Rider_AiEnterApproach(void);
extern void Ov245_SeedTimerFireAttack2ThenAdvanceSlot(void);
extern void Ov245_ComputeTargetDeltaThenAdvance(void);
extern void Ov245_Rider_AiEnterSpinAttack(void);
extern void Ov245_ConfigSubStateThenAdvanceSlot(void);
extern void Ov245_SetVisFlagPose7PlayAdvance(void);
extern void Ov245_ConfigHw60FlagsBeginAction4a(void);
extern void Ov245_FinishEnter(void);

void Ov245_Rider_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xce;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
        ((B8 *)(*(int *)(ctx[0] + 0x388) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov245_EnterBlockPose);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov245_CrashEnter);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov245_Rider_AiEnterApproach);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov245_SeedTimerFireAttack2ThenAdvanceSlot);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov245_ComputeTargetDeltaThenAdvance);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov245_Rider_AiEnterSpinAttack);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov245_ConfigSubStateThenAdvanceSlot);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov245_SetVisFlagPose7PlayAdvance);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov245_ConfigHw60FlagsBeginAction4a);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov245_FinishEnter);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
