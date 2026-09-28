/* Unless the gate byte at *(child+0xc) is set, mark sub-state 4 and dispatch. */
extern int SetIndexedSlot(int a, int b, void *handler);
void Ov274_AiQueue4OnFlagClear(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(unsigned char *)*(int *)(child + 0xc) != 0) return;
    *(signed char *)(*(int *)child + 0x1c7) = 4;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
}
