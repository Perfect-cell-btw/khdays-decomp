/* Unless the busy byte at *(child+4)+0xad is set, copy the sub-state byte +0x5d into
 * (*child)+0x1c7 and dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov212_AiQueueStoredOnAnimEnd(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = *(signed char *)(child + 0x5d);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
