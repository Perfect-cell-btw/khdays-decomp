/* Unless the busy byte at *(child+8) is set, invoke Task_MarkFinished. */
extern void Task_MarkFinished(int a);
void Ov244_FinishWhenChildAnimEnds(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 8) != 0) return;
    Task_MarkFinished(param_1);
}
