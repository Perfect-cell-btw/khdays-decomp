/* Ov218_AiDispatchAction -- ov218's move dispatcher. The plain family shape: -1 at ctx[0]+0x1c7 means
 * nothing queued, the id is copied to +0x1c6 and it is that copy the switch reads, and the slot is
 * cleared on every path.
 *
 * The reset drops 0xc6 from the hw60 hi-byte and bits 0-1 of the halfword at +0x1ae, then touches
 * the sub-object at ctx[0]+0x388 TWICE: bit 0 on, then bit 1 off. The two are separate read-modify
 * -write sequences in the ROM (each reloads ctx[0] and +0x388), so they stay separate expressions.
 *
 * Case 3 is out of order (after 7) as everywhere else, and 8 and 9 are swapped on top of that.
 *
 * Both the hw60 and the +8 writes carry the lsl/lsr trunc pair -> bitfield form. See
 * codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov218_stateSetFlagsClearBit(void);
extern void Ov218_AiStep_QueueAction2(void);
extern void Ov218_AiEnterIdle(void);
extern void Ov218_PickTarget(void);
extern void Ov218_Reaction_PollBranchTick(void);
extern void Ov218_AiEnterAnim4IfTarget(void);
extern void Ov218_AimEntry(void);
extern void Ov218_AimedStrikeEntry(void);
extern void Ov218_AiEnterAnim8WithUpdate(void);
extern void Ov218_AiQueueAction4WithDelay(void);
extern void Ov218_Release(void);
extern void Ov218_SetPoseThenAdvanceSlot(void);

void Ov218_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x388) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x388) + 8))->f &= ~2;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov218_stateSetFlagsClearBit);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov218_AiStep_QueueAction2);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov218_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov218_PickTarget);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov218_Reaction_PollBranchTick);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov218_AiEnterAnim4IfTarget);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov218_AimEntry);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov218_AimedStrikeEntry);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov218_AiEnterAnim8WithUpdate);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov218_AiQueueAction4WithDelay);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov218_Release);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov218_SetPoseThenAdvanceSlot);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
