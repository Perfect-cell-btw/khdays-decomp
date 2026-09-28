/* Clear +0x34 and tail-call the dispatcher. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov201_TimerEaseInterp(int);
void Ov201_AiGoToTimerEaseInterp(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 0x34) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov201_TimerEaseInterp);
}
