/* Latch the pending state byte (+0x1c7) into +0x1c6; if valid and it names
 * transition 0/1/2, dispatch the matching handler; then mark +0x1c7 consumed. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov212_EnterReactionReset(void);
extern void Ov212_EnterTrackState(void);
extern void Ov212_Stop(void);
void Ov212_AiDispatchPendingAction(int param_1) {
    int child = *(int *)(param_1 + 4);
    signed char v = *(signed char *)(*(int *)child + 0x1c7);
    if (v != -1) {
        *(signed char *)(*(int *)child + 0x1c6) = v;
        switch (*(signed char *)(*(int *)child + 0x1c6)) {
        case 0:
            SetIndexedSlot(param_1, 1, (void *)&Ov212_EnterReactionReset);
            break;
        case 1:
            SetIndexedSlot(param_1, 1, (void *)&Ov212_EnterTrackState);
            break;
        case 2:
            SetIndexedSlot(param_1, 1, (void *)&Ov212_Stop);
            break;
        }
    }
    *(signed char *)(*(int *)child + 0x1c7) = -1;
}
