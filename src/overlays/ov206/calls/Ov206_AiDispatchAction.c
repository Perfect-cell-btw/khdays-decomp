/* Ov206_AiDispatchAction -- ov206's move dispatcher, the plainest of the family: -1 at ctx[0]+0x1c7
 * means nothing queued, the id is copied to +0x1c6 and it is that copy the switch reads, and the
 * slot is cleared on every path.
 *
 * The reset drops 0xce from the hw60 hi-byte and bit 0 of the halfword at +0x1ae, then sets bit 0
 * on the sub-object at ctx[0]+0x3ac and bits 0-1 on the one at +0x3b0.
 *
 * Case 3 is out of order (after 7), as in every other dispatcher in this codebase -- the table is
 * index-ordered but the bodies follow source order.
 *
 * The hw60 write HAS the lsl#0x10/lsr#0x10 trunc pair -> bitfield form; the +8 fields are
 * byte-in-word. See codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov206_AiLockAndPostUpdate(void);
extern void Ov206_AiEnterHold(void);
extern void Ov206_SetPoseThenAdvanceSlot(void);
extern void Ov206_AiEnterSteer(void);
extern void Ov206_AiEnterAttack2(void);
extern void Ov206_AiEnterLanding(void);
extern void Ov206_AiEnterChargeBreak(void);
extern void Ov206_SpawnEffect4dTwoNodeClearB(void);
extern void Ov206_AiEnterStomp(void);
extern void Ov206_AiEnterIdle(void);
extern void Ov206_AiEnterThrow(void);
extern void Ov206_AiEnterRockFlight(void);
extern void Ov206_AiLockAndPostUpdateB(void);

void Ov206_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xce;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~1;
        ((B8 *)(*(int *)(ctx[0] + 0x3ac) + 8))->f |= 1;
        ((B8 *)(*(int *)(ctx[0] + 0x3b0) + 8))->f |= 3;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov206_AiLockAndPostUpdate);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov206_AiEnterHold);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov206_SetPoseThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov206_AiEnterSteer);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov206_AiEnterAttack2);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov206_AiEnterLanding);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov206_AiEnterChargeBreak);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov206_SpawnEffect4dTwoNodeClearB);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov206_AiEnterStomp);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov206_AiEnterIdle);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov206_AiEnterThrow);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov206_AiEnterRockFlight);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov206_AiLockAndPostUpdateB);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
