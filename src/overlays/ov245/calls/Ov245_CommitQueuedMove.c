/* Commit the queued move and dispatch its handler (ov245). First refresh the approach
 * factor: FX_Inv(gap, reach) over the distance from the target's point (ctx[2]+8) to the
 * actor's reach envelope, both measured from ctx+0x3c + 0xf000. Then, if a move is queued
 * at owner+0x1c7 (-1 = none), latch it as the current move (+0x1c6), clear the two stance
 * flags (hw60 hi 0x82 and owner+0x1ae bits 0-1), mark the sub-object at owner+0x3b4 live
 * (bit 0) and not-done (bit 1), reset the timer, run the move's handler and clear the
 * queue slot.
 *
 * The case order below is the ROM's SOURCE order, recovered from the jump table with
 * tools/switchorder.py -- the bodies are laid out in source order while the table is
 * indexed by value, so sorting the table's targets by address gives it directly. It is
 * 0, 2, 4, 5, 6, 7, 8, 9, 10, 3 (case 3 last, and its pool entry is likewise the highest
 * -- it reads like a move added after the others). Case 1 has no body of its own and
 * falls to the default. Written this way the whole 552-byte layout was byte-exact on the
 * first compile.
 *
 * FX_Inv takes TWO arguments here despite the name -- the ROM computes both r0 and r1,
 * and the tree's other callers agree (`FX_Inv(gap, reach)`); it is a divide. */
struct hw60 { unsigned short lo : 8, hi : 8; };
struct b8 { unsigned f : 8; };

extern int FX_Div(int a, int b);
extern void SetIndexedSlot(void *self, int idx, void *cb);
extern void Ov245_stateSetFlagsClearBit(void);
extern void Ov245_LandingDecision(void);
extern void Ov245_AiEnterDescend(void);
extern void Ov245_SetPose2ThenAdvanceSlot(void);
extern void Ov245_DescendEnter(void);
extern void Ov245_DiveEnter(void);
extern void Ov245_AiEnterFlight(void);
extern void Ov245_AiEnterHoverArm(void);
extern void Ov245_AiEnterWaitStop(void);
extern void Ov245_AiStep_SetFlags3AndEnd(void);

void Ov245_CommitQueuedMove(void *self) {
    int *ctx = *(int **)((char *)self + 4);
    int t;
    signed char slot;

    t = ctx[0xf] + 0xf000;
    ctx[0xe] = FX_Div(*(int *)(ctx[2] + 8) - t, -0xb000 - t);
    slot = *(signed char *)(*ctx + 0x1c7);
    if (slot == -1) {
        return;
    }
    *(char *)(*ctx + 0x1c6) = slot;
    ((struct hw60 *)(*ctx + 0x60))->hi &= ~0x82;
    *(unsigned short *)(*ctx + 0x1ae) &= ~3;
    ((struct b8 *)(*(int *)(*ctx + 0x3b4) + 8))->f |= 1;
    ((struct b8 *)(*(int *)(*ctx + 0x3b4) + 8))->f &= ~2;
    ctx[0xf] = 0;
    switch (*(signed char *)(*ctx + 0x1c6)) {
    case 0:  SetIndexedSlot(self, 1, Ov245_stateSetFlagsClearBit); break;
    case 2:  SetIndexedSlot(self, 1, Ov245_LandingDecision); break;
    case 4:  SetIndexedSlot(self, 1, Ov245_AiEnterDescend); break;
    case 5:  SetIndexedSlot(self, 1, Ov245_SetPose2ThenAdvanceSlot); break;
    case 6:  SetIndexedSlot(self, 1, Ov245_DescendEnter); break;
    case 7:  SetIndexedSlot(self, 1, Ov245_DiveEnter); break;
    case 8:  SetIndexedSlot(self, 1, Ov245_AiEnterFlight); break;
    case 9:  SetIndexedSlot(self, 1, Ov245_AiEnterHoverArm); break;
    case 10: SetIndexedSlot(self, 1, Ov245_AiEnterWaitStop); break;
    case 3:  SetIndexedSlot(self, 1, Ov245_AiStep_SetFlags3AndEnd); break;
    }
    *(char *)(*ctx + 0x1c7) = -1;
}
