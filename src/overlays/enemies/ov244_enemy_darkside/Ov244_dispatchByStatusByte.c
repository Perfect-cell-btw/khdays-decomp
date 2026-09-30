/* Latch the pending state byte (+0x1c7) into +0x1c6; if it names transition 0 or
 * 1, dispatch the matching handler; then mark +0x1c7 consumed (-1). */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov244_ClearSetVisFlagsAdvance(void);
extern void Ov244_AiEnterDiveImpact(void);
void Ov244_dispatchByStatusByte(int param_1) {
    int child = *(int *)(param_1 + 4);
    signed char v = *(signed char *)(*(int *)child + 0x1c7);
    if (v == -1) return;
    *(signed char *)(*(int *)child + 0x1c6) = v;
    switch (*(signed char *)(*(int *)child + 0x1c6)) {
    case 0:
        SetIndexedSlot(param_1, 1, (void *)&Ov244_ClearSetVisFlagsAdvance);
        break;
    case 1:
        SetIndexedSlot(param_1, 1, (void *)&Ov244_AiEnterDiveImpact);
        break;
    }
    *(signed char *)(*(int *)child + 0x1c7) = -1;
}
