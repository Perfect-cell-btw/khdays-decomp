/* Accumulate the owner rate (+0x2c) into the timer at (child)+8; once it reaches 0x800,
 * advance to the next state. */
extern void Task_MarkFinished(int a);
void Ov235_FinishAfterDelay(int param_1) {
    int child = *(int *)(param_1 + 4);
    int t = *(int *)(child + 8) + *(int *)(*(int *)param_1 + 0x2c);
    *(int *)(child + 8) = t;
    if (t < 0x800) return;
    Task_MarkFinished(param_1);
}
