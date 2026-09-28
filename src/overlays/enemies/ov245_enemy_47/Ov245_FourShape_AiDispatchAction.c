/* Latch the queued sub-state +0x1c7 into +0x1c6, clear bit1 of the hw60 hi byte, dispatch the
 * matching handler, then reset +0x1c7 to -1. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_EnterState4038(int);
extern int Ov245_ChargeUpTick3(int);
extern int Ov245_GrabCheck(int);
struct hw60 { unsigned short lo : 8, hi : 8; };
void Ov245_FourShape_AiDispatchAction(int param_1) {
    int owner = *(int *)(param_1 + 4);
    int sub = *(signed char *)(*(int *)owner + 0x1c7);
    if (sub != -1) {
        *(signed char *)(*(int *)owner + 0x1c6) = sub;
        ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~2;
        switch (*(signed char *)(*(int *)owner + 0x1c6)) {
        case 0: SetIndexedSlot(param_1, 1, (void *)&Ov245_EnterState4038); break;
        case 1: SetIndexedSlot(param_1, 1, (void *)&Ov245_ChargeUpTick3); break;
        case 2: SetIndexedSlot(param_1, 1, (void *)&Ov245_GrabCheck); break;
        }
    }
    *(signed char *)(*(int *)owner + 0x1c7) = -1;
}
