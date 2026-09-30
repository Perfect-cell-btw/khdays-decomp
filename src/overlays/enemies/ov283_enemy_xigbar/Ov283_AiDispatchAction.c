/* Ov283_AiDispatchAction -- ov283's move dispatcher. The plain family shape: -1 at ctx[0]+0x1c7 means
 * nothing queued, the id is copied to +0x1c6 and it is that copy the switch reads, and the slot is
 * cleared on every path.
 *
 * The reset drops 0xc6 from the hw60 hi-byte and bits 0-1 of the halfword at +0x1ae, then sets bit
 * 0 on the sub-object at ctx[0]+0x388.
 *
 * Case 1 is absent from the switch. The source case order (0,2,4,5,6,10,8,9,7,11,3) is the body
 * order -- 10 and 7 are out of place as well as the usual 3.
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
extern void Ov283_stateSetFlagsClearBit(void);
extern void Ov283_AiEnterWalk(void);
extern void Ov283_AiEnterCircle(void);
extern void Ov283_HopEntry(void);
extern void Ov283_AiEnterBarrage(void);
extern void Ov283_BounceEntry(void);
extern void Ov283_AimStart(void);
extern void Ov283_WarpStart(void);
extern void Ov283_AiEnterVolley(void);
extern void Ov283_SwipePick(void);
extern void Ov283_AiEnterPatrol(void);

void Ov283_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x388) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov283_stateSetFlagsClearBit);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov283_AiEnterWalk);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov283_AiEnterCircle);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov283_HopEntry);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov283_AiEnterBarrage);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov283_BounceEntry);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov283_AimStart);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov283_WarpStart);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov283_AiEnterVolley);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov283_SwipePick);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov283_AiEnterPatrol);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
