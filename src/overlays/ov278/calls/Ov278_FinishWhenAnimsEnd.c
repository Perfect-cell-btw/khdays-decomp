/* Unless either busy byte at *(child+4)+0xad or *(child+8)+0xad is set, invoke Task_MarkFinished. */
extern void Task_MarkFinished(int a);
void Ov278_FinishWhenAnimsEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0 ||
        *(unsigned char *)(*(int *)(child + 8) + 0xad) != 0) return;
    Task_MarkFinished(param_1);
}
