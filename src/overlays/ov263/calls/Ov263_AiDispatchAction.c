/* Ov263_AiDispatchAction -- ov231's move dispatcher, the counterpart of Ov228_AiDispatchAction: play
 * whatever move is queued at ctx[0]+0x1c7 and clear the slot. -1 means nothing queued and the
 * whole body is skipped, but the slot is cleared either way.
 *
 * Before dispatching it resets the move state: bit 0 of the halfword at +0x1ae, the probe bitmask
 * at ctx+0x4d, bit 0 SET and bit 1 CLEARED on the target's byte field at +8, and the hw60 flags.
 * The id is then copied to +0x1c6, and it is that copy the switch reads.
 *
 * The 15 handlers are the ov231 state family -- Ov263_AiEnterStandby (the tick),
 * Ov263_AiEnterStrafe (the sidestep chooser), and so on. Case 12 is absent from the switch; its
 * jump-table entry points at the default, which is how mwcc fills a gap in an otherwise dense
 * table.
 *
 * Source case order is 0,1,2,4,11,5,6,7,8,9,10,3,13,14 -- that is the order the ROM lays the
 * bodies out, and with a jump table the body order IS the source order (the table itself is
 * index-ordered). Do not tidy it.
 *
 * ★ Both hw60 forms appear here back to back, and they need OPPOSITE C (see codegen-cracks.md):
 * `hi |= 0x40` has no `lsl#0x10 ; lsr#0x10` trunc pair -> explicit extract/reassemble with
 * `v & ~0xff00` for the lo-byte keep; `hi &= ~0x9e` has the pair -> bitfield form. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov263_AiEnterStandby(void);
extern void Ov263_AiEnterWait(void);
extern void Ov263_AiEnterIdle(void);
extern void Ov263_AiEnterStrafe(void);
extern void Ov263_Reaction_BiasFramesAndDispatch(void);
extern void Ov263_AiEnterFireVolley(void);
extern void Ov263_AiEnterLunge(void);
extern void Ov263_AiEnterLungeB(void);
extern void Ov263_AiEnterSlam(void);
extern void Ov263_AiEnterPoseSequence(void);
extern void Ov263_AiEnterPoseSequenceB(void);
extern void Ov263_AiLockAndPostUpdate(void);
extern void Ov263_AiEnterHold(void);
extern void Ov263_AiEnterAim(void);

void Ov263_AiDispatchAction(int self) {
    int *ctx;
    unsigned short v;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
        *(unsigned char *)((char *)ctx + 0x4d) = 0;
        ((B8 *)(*(int *)(ctx[0] + 0x3bc) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x3bc) + 8))->f &= ~2;

        v = *(unsigned short *)(ctx[0] + 0x60);
        *(unsigned short *)(ctx[0] + 0x60) =
            (unsigned short)((v & ~0xff00)
                             | (((((unsigned int)v << 0x10) >> 0x18 | 0x40) << 0x18) >> 0x10));
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x9e;

        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov263_AiEnterStandby);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov263_AiEnterWait);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov263_AiEnterIdle);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov263_AiEnterStrafe);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov263_Reaction_BiasFramesAndDispatch);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov263_AiEnterFireVolley);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov263_AiEnterLunge);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov263_AiEnterLungeB);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov263_AiEnterSlam);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov263_AiEnterPoseSequence);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov263_AiEnterPoseSequenceB);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov263_AiLockAndPostUpdate);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov263_AiEnterHold);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov263_AiEnterAim);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
