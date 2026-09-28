/* When ready (+0x50 == 1) forward the handle at +0x214 to Ov212_AiQueueAction0 and return its
 * result; otherwise return param_1. */
extern int Ov212_AiQueueAction0(int arg);
int Ov212_ForwardToAiTaskWhenReady(int param_1) {
    if (*(int *)(param_1 + 0x50) == 1) {
        return Ov212_AiQueueAction0(*(int *)(param_1 + 0x214));
    }
    return param_1;
}
