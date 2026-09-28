/* Mark sub-state 5 at (*child)+0x1c7 and dispatch (no handler). */
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov272_AiStep_QueueAction5(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(signed char *)(*(int *)child + 0x1c7) = 5;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
