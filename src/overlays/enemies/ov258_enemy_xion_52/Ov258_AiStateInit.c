/* Point +8 at obj+0xb0, set sub-state +0x1c6=1 and +0x1c7=-1, clear bit0 of the hw60 hi byte and
 * +0x1ae, then hand off across the 020d00c4 / 020d020c / 020d0158 trio. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov258_AiDispatchPendingAction(int);
extern int Ov258_ItemFlightStart(int);
extern int Ov258_ItemFollowHand(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov258_AiStateInit(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 8) = *(int *)owner + 0xb0;
    *(unsigned char *)(*(int *)owner + 0x1c6) = 1;
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~1;
    *(unsigned short *)(*(int *)owner + 0x1ae) &= ~1;
    SetIndexedSlot(param_1, 0, (void *)&Ov258_AiDispatchPendingAction);
    SetIndexedSlot(param_1, 1, (void *)&Ov258_ItemFlightStart);
    SetIndexedSlot(param_1, 2, (void *)&Ov258_ItemFollowHand);
}
