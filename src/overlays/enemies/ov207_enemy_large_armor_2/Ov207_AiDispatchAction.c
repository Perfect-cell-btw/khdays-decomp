/* Ov207_AiDispatchAction -- ov206's move dispatcher, the plainest of the family: -1 at ctx[0]+0x1c7
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
extern void Ov207_AiLockAndPostUpdate(void);
extern void Ov207_AiEnterHold(void);
extern void Ov207_SetPoseThenAdvanceSlot(void);
extern void Ov207_AiEnterSteer(void);
extern void Ov207_AiEnterAttack2(void);
extern void Ov207_AiEnterLanding(void);
extern void Ov207_AiEnterChargeBreak(void);
extern void Ov207_SpawnEffect4dTwoNodeClearB(void);
extern void Ov207_AiEnterStomp(void);
extern void Ov207_AiEnterIdle(void);
extern void Ov207_AiEnterThrow(void);
extern void Ov207_AiEnterRockFlight(void);
extern void Ov207_AiLockAndPostUpdateB(void);

void Ov207_AiDispatchAction(int self) {
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
            SetIndexedSlot(self, 1, Ov207_AiLockAndPostUpdate);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov207_AiEnterHold);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov207_SetPoseThenAdvanceSlot);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov207_AiEnterSteer);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov207_AiEnterAttack2);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov207_AiEnterLanding);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov207_AiEnterChargeBreak);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov207_SpawnEffect4dTwoNodeClearB);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov207_AiEnterStomp);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov207_AiEnterIdle);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov207_AiEnterThrow);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov207_AiEnterRockFlight);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov207_AiLockAndPostUpdateB);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
