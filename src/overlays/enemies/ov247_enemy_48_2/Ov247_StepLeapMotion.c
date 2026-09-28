/* Accumulate the owner's rate (+0x2c) into the child timer (+0x3c); once it passes
 * 0x444, reset it and dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov247_AiJumpRiseTick(void);
void Ov247_StepLeapMotion(int param_1) {
    int child = *(int *)(param_1 + 4);
    int c = *(int *)(child + 0x3c) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 0x3c) = c;
    if (c <= 0x444) return;
    *(int *)(child + 0x3c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov247_AiJumpRiseTick);
}
