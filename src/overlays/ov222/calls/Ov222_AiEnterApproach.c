/* Notify Ov222_SetModeAndResetCounters with the child fields, then dispatch. */
extern void Ov222_SetModeAndResetCounters(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov222_AiApproachTick(void);
void Ov222_AiEnterApproach(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov222_SetModeAndResetCounters(*(int *)child, *(int *)(child + 0x78));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov222_AiApproachTick);
}
