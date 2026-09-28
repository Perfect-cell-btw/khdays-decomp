/* Ov238_AiDispatchAction -- ov238's move dispatcher. The plain family shape: -1 at ctx[0]+0x1c7 means
 * nothing queued, the id is copied to +0x1c6 and it is that copy the switch reads, and the slot is
 * cleared on every path.
 *
 * The reset drops 0xc6 from the hw60 hi-byte and bits 0-1 of the halfword at +0x1ae, then sets bit
 * 0 on the sub-object at ctx[0]+0x38c.
 *
 * Notably case 3 is in its natural position here -- the only dispatcher so far where it is. Cases
 * 8 and 7 are swapped instead.
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
extern void Ov238_AiEnterRecover(void);
extern void Ov238_AiStep_QueueAction2(void);
extern void Ov238_AiEnterIdle(void);
extern void Ov238_AiEnterWalk(void);
extern void Ov238_EnterTaunt(void);
extern void Ov238_AiEnterSwipe(void);
extern void Ov238_AiEnterCombo(void);
extern void Ov238_AiEnterRoar(void);
extern void Ov238_AiEnterCharge(void);
extern void Ov238_AiEnterRoarTurn(void);

void Ov238_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x38c) + 8))->f |= 1;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov238_AiEnterRecover);
            break;
        case 1:
            SetIndexedSlot(self, 1, Ov238_AiStep_QueueAction2);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov238_AiEnterIdle);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov238_AiEnterWalk);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov238_EnterTaunt);
            break;
        case 5:
            SetIndexedSlot(self, 1, Ov238_AiEnterSwipe);
            break;
        case 6:
            SetIndexedSlot(self, 1, Ov238_AiEnterCombo);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov238_AiEnterCharge);
            break;
        case 7:
            SetIndexedSlot(self, 1, Ov238_AiEnterRoar);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov238_AiEnterRoarTurn);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
