/* When ready (+0x50 == 1) forward the handle at +0x214 to Ov238_QueueAction1 and return its
 * result; otherwise return param_1. */
extern int Ov238_QueueAction1(int arg);
int Ov238_ForwardToAiTaskWhenReady(int param_1) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov238_QueueAction1(*(int *)(param_1 + 0x214));
    }
    return param_1;
}
