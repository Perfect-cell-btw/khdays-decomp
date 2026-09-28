/* Clear bit 1 of the hw60 high byte, set +0x1ae bit 0, then dispatch. */
extern int SetIndexedSlot(int, int, void *);
struct hw60 { unsigned short lo : 8; unsigned short hi : 8; };
extern int Ov253_AiStep_QueueAction2(int);
void Ov253_AiEnterRest(int param_1) {
    int owner = *(int *)(param_1 + 4);
    ((struct hw60 *)(*(int *)owner + 0x60))->hi &= ~2;
    *(unsigned short *)(*(int *)owner + 0x1ae) |= 1;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiStep_QueueAction2);
}
