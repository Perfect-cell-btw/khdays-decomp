/* Ov260_AiDispatchAction -- ov260's move dispatcher.
 *
 * Moves 7 and 8 run the SAME handler (Ov260_StaggerEntry) and differ only in the byte they park
 * at ctx+0x78 afterwards -- 1 for one, 3 for the other. So that field is the handler's parameter,
 * and the two moves are one behaviour with a variant selector.
 *
 * The "nothing queued" case RETURNS outright (a predicated `popeq`) rather than falling into the
 * shared -1 store. Case 1 is absent from the switch; case 3 is out of order (last) as everywhere.
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
extern void Ov260_stateSetFlagsClearBit(void);
extern void Ov260_AiEnterPlay(void);
extern void Ov260_AiEnterTakeOff(void);
extern void Ov260_AiEnterSwoop(void);
extern void Ov260_SlamEntry(void);
extern void Ov260_StaggerEntry(void);
extern void Ov260_AiEnterAnim6(void);
extern void Ov260_AiEnterAnim7(void);
extern void Ov260_TurnEntry(void);
extern void Ov260_SwipeEntry(void);
extern void Ov260_BlastEntry(void);
extern void Ov260_AiStep_SetFlags3AndEnd(void);

void Ov260_AiDispatchAction(int self) {
    int *ctx;

    ctx = *(int **)(self + 4);
    if (*(signed char *)(ctx[0] + 0x1c7) == -1) {
        return;
    }

    *(signed char *)(ctx[0] + 0x1c6) = *(signed char *)(ctx[0] + 0x1c7);
    ((Hw60 *)(ctx[0] + 0x60))->hi &= ~0xc6;
    *(unsigned short *)(ctx[0] + 0x1ae) &= ~3;
    ((B8 *)(*(int *)(ctx[0] + 0x418) + 8))->f |= 1;

    switch (*(signed char *)(ctx[0] + 0x1c6)) {
    case 0:
        SetIndexedSlot(self, 1, Ov260_stateSetFlagsClearBit);
        break;
    case 2:
        SetIndexedSlot(self, 1, Ov260_AiEnterPlay);
        break;
    case 4:
        SetIndexedSlot(self, 1, Ov260_AiEnterTakeOff);
        break;
    case 5:
        SetIndexedSlot(self, 1, Ov260_AiEnterSwoop);
        break;
    case 6:
        SetIndexedSlot(self, 1, Ov260_SlamEntry);
        break;
    case 7:
        SetIndexedSlot(self, 1, Ov260_StaggerEntry);
        *(unsigned char *)((char *)ctx + 0x78) = 1;
        break;
    case 8:
        SetIndexedSlot(self, 1, Ov260_StaggerEntry);
        *(unsigned char *)((char *)ctx + 0x78) = 3;
        break;
    case 9:
        SetIndexedSlot(self, 1, Ov260_AiEnterAnim6);
        break;
    case 10:
        SetIndexedSlot(self, 1, Ov260_AiEnterAnim7);
        break;
    case 11:
        SetIndexedSlot(self, 1, Ov260_TurnEntry);
        break;
    case 12:
        SetIndexedSlot(self, 1, Ov260_SwipeEntry);
        break;
    case 13:
        SetIndexedSlot(self, 1, Ov260_BlastEntry);
        break;
    case 3:
        SetIndexedSlot(self, 1, Ov260_AiStep_SetFlags3AndEnd);
        break;
    }

    *(signed char *)(ctx[0] + 0x1c7) = -1;
}
