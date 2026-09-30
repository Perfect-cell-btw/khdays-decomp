/* Latch the pending state byte (+0x1c7) into +0x1c6; if valid and it names
 * transition 0/1/2, dispatch the matching handler; then mark +0x1c7 consumed. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov253_StopEnter(void);
extern void Ov253_BurstEnter(void);
extern void Ov253_BoxEnter(void);
void Ov253_AiDispatchPendingAction(int param_1) {
    int child = *(int *)(param_1 + 4);
    signed char v = *(signed char *)(*(int *)child + 0x1c7);
    if (v != -1) {
        *(signed char *)(*(int *)child + 0x1c6) = v;
        switch (*(signed char *)(*(int *)child + 0x1c6)) {
        case 0:
            SetIndexedSlot(param_1, 1, (void *)&Ov253_StopEnter);
            break;
        case 1:
            SetIndexedSlot(param_1, 1, (void *)&Ov253_BurstEnter);
            break;
        case 2:
            SetIndexedSlot(param_1, 1, (void *)&Ov253_BoxEnter);
            break;
        }
    }
    *(signed char *)(*(int *)child + 0x1c7) = -1;
}
