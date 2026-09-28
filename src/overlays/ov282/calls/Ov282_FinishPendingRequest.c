/* If a pending request is queued at (param_1)+0x194, resolve it against +0x3c, run the
 * follow-up, and clear the request. */
extern int FindListEntryByField4(int a, int b);
extern void Task_MarkFinished(int a);
void Ov282_FinishPendingRequest(int param_1) {
    int req = *(int *)(param_1 + 0x194);
    if (req == 0) return;
    Task_MarkFinished(FindListEntryByField4(*(int *)(param_1 + 0x3c), req));
    *(int *)(param_1 + 0x194) = 0;
}
