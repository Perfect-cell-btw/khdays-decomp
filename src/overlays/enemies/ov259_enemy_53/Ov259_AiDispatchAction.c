/* Ov259_AiDispatchAction -- ov259's move dispatcher. Two things set it apart from the rest of the
 * family:
 *
 *  - the cooldown at ctx+0x94 is 0x32 or 0x1e depending on the flag at ctx+0x4c, so whatever that
 *    flag is, it makes the object slower to act;
 *  - there is a SECOND switch before the dispatch: moves 10..17 clear ctx+0x48 and everything else
 *    sets it to 1. It is written out as eight case labels because the ROM builds a full jump table
 *    for it -- a range test (`move >= 10 && move <= 17`) collapses to three instructions instead.
 *
 * Cases 1, 5, 6 and 7 are absent from the move switch; 15 dispatches the same handler as 3.
 *
 * The hw60 write HAS the lsl#0x10/lsr#0x10 trunc pair -> bitfield form; the field at +8 of
 * *(ctx[0]+0x404) is a byte-in-word. See codegen-cracks.md. */

typedef struct {
    unsigned short lo : 8;
    unsigned short hi : 8;
} Hw60;

typedef struct {
    unsigned f : 8;
} B8;

extern void SetIndexedSlot(int self, int slot, void (*cb)(void));
extern void Ov259_stateSetFlagsClearBit(void);
extern void Ov259_AiResetMoveState(void);
extern void Ov259_ShootEntry(void);
extern void Ov259_AiEnterTaunt(void);
extern void Ov259_AiEnterDash(void);
extern void Ov259_AiEnterRise(void);
extern void Ov259_FaceTargetOnEntry(void);
extern void Ov259_WaitEntry(void);
extern void Ov259_JumpEntry(void);
extern void Ov259_AiEnterFinisher(void);
extern void Ov259_DownEntry(void);
extern void Ov259_ChargeEntry(void);
extern void Ov259_SlamEntry(void);
extern void Ov259_LungeRestartEntry(void);

void Ov259_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) != -1) {
        *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
        ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0x86;
        *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
        ((B8 *)(*(int *)(ctx[0] + 0x404) + 8))->f |= 1;
        *(unsigned char *)((char *)ctx + 0xae) = 0;
        ctx[0x25] = ctx[0x13] != 0 ? 0x32 : 0x1e;

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            ctx[0x12] = 0;
            break;
        default:
            ctx[0x12] = 1;
            break;
        }

        switch (*(signed char *)(ctx[0] + 0x1c6)) {
        case 0:
            SetIndexedSlot(self, 1, Ov259_stateSetFlagsClearBit);
            break;
        case 2:
            SetIndexedSlot(self, 1, Ov259_AiResetMoveState);
            break;
        case 4:
            SetIndexedSlot(self, 1, Ov259_FaceTargetOnEntry);
            break;
        case 3:
            SetIndexedSlot(self, 1, Ov259_DownEntry);
            break;
        case 8:
            SetIndexedSlot(self, 1, Ov259_ShootEntry);
            break;
        case 9:
            SetIndexedSlot(self, 1, Ov259_AiEnterTaunt);
            break;
        case 10:
            SetIndexedSlot(self, 1, Ov259_AiEnterDash);
            break;
        case 11:
            SetIndexedSlot(self, 1, Ov259_AiEnterRise);
            break;
        case 12:
            SetIndexedSlot(self, 1, Ov259_WaitEntry);
            break;
        case 13:
            SetIndexedSlot(self, 1, Ov259_JumpEntry);
            break;
        case 14:
            SetIndexedSlot(self, 1, Ov259_AiEnterFinisher);
            break;
        case 15:
            SetIndexedSlot(self, 1, Ov259_DownEntry);
            break;
        case 16:
            SetIndexedSlot(self, 1, Ov259_ChargeEntry);
            break;
        case 17:
            SetIndexedSlot(self, 1, Ov259_SlamEntry);
            break;
        case 18:
            SetIndexedSlot(self, 1, Ov259_LungeRestartEntry);
            break;
        }
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
