/* Notify Ov225_SetModeAndResetCounters with the child fields, then dispatch. */
extern void Ov225_SetModeAndResetCounters(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov225_AiApproachTick(void);
void Ov225_AiEnterApproach(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov225_SetModeAndResetCounters(*(int *)child, *(int *)(child + 0x78));
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov225_AiApproachTick);
}
