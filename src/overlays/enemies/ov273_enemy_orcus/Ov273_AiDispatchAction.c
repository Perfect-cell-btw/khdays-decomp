/* Ov273_AiDispatchAction -- ov213's move dispatcher. The family shape, but with three things of its
 * own:
 *
 *  - the "nothing queued" case RETURNS outright (a predicated `popeq`) instead of falling into the
 *    shared -1 store the way ov210/ov221/ov225/ov228/ov231 do. Written as an early return here;
 *    the `if (x != -1) { ... }` form gives them a branch to the tail instead;
 *  - the timer at +0x48 is refreshed to (*self)[0x2c] * 30 / 10, kept unfolded because that is the
 *    multiply-then-magic-divide the ROM emits;
 *  - +0x1b0 comes from the BYTE at ctx+0x74, not from a halfword.
 *
 * Cases 2 and 5 both dispatch Ov273_EnterIdle but have their own bodies -- mwcc did not merge
 * them, so they are two separate arms.
 *
 * Form notes: `hi |= 0x40` has no lsl#0x10/lsr#0x10 trunc pair -> explicit extract/reassemble;
 * `hi &= ~0x8e` has one -> bitfield. See codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov273_EnterStopAnimRaiseFlags86(void);
extern void Ov273_EnterRetreat(void);
extern void Ov273_AiEnterWander(void);
extern void Ov273_EnterIdle(void);
extern void Ov273_AiEnterScaleBranch(void);
extern void Ov273_AiEnterBackOff(void);
extern void Ov273_Reaction_BuildTransformAndDispatch(void);
extern void Ov273_AiEnterShockwave(void);
extern void Ov273_AiEnterSink(void);
extern void Ov273_EnterScatter(void);
extern void Ov273_EnterAttack(void);
extern void Ov273_AiEnterHover(void);
extern void Ov273_EnterPose19State(void);
extern void Ov273_EnterGuard(void);
extern void Ov273_EnterStagger(void);

void Ov273_AiDispatchAction(int self) {
    int *ctx;
    unsigned short v;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) == -1) {
        return;
    }

    v = *(unsigned short *)(ctx[0] + 0x60);
    *(unsigned short *)(ctx[0] + 0x60) =
        (unsigned short)((v & ~0xff00)
                         | (((((unsigned int)v << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
    ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x8e;
    *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
    ((B8 *)(*(int *)(ctx[0] + 0x3d4) + 8))->f |= 1;

    ctx[0x12] = *(int *)(*(int *)self + 0x2c) * 30 / 10;
    *(unsigned short *)(ctx[0] + 0x1b0) = *(unsigned char *)((char *)ctx + 0x74);
    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);

    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov273_EnterStopAnimRaiseFlags86);
        break;
    case 1:
        SetIndexedSlot(self, 1, Ov273_EnterRetreat);
        break;
    /* Case 2 re-queues itself as move 5 and FALLS THROUGH into it -- the ROM's case-5 table entry
     * points 8 bytes into case 2's body, past the store. (The store is dead in the original: the
     * tail overwrites +0x1c7 with -1 regardless. Reproduced because the ROM has it.) */
    case 2:
        *(signed char *)(ctx[0] + 0x1c7) = 5;
        /* fall through */
    case 5:
        SetIndexedSlot(self, 1, Ov273_EnterIdle);
        break;
    case 4:
        SetIndexedSlot(self, 1, Ov273_AiEnterWander);
        break;
    case 6:
        SetIndexedSlot(self, 1, Ov273_AiEnterScaleBranch);
        break;
    case 7:
        SetIndexedSlot(self, 1, Ov273_AiEnterBackOff);
        break;
    case 8:
        SetIndexedSlot(self, 1, Ov273_Reaction_BuildTransformAndDispatch);
        break;
    case 9:
        SetIndexedSlot(self, 1, Ov273_AiEnterShockwave);
        break;
    case 10:
        SetIndexedSlot(self, 1, Ov273_AiEnterSink);
        break;
    case 11:
        SetIndexedSlot(self, 1, Ov273_EnterScatter);
        break;
    case 12:
        SetIndexedSlot(self, 1, Ov273_EnterAttack);
        break;
    case 13:
        SetIndexedSlot(self, 1, Ov273_AiEnterHover);
        break;
    case 14:
        SetIndexedSlot(self, 1, Ov273_EnterPose19State);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov273_EnterGuard);
        break;
    case 15:
        SetIndexedSlot(self, 1, Ov273_EnterStagger);
        break;
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
