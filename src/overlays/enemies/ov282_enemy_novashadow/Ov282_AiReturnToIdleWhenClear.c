/* Unless the +4 field is set, register the handler. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov282_AiEnterIdle(int);
void Ov282_AiReturnToIdleWhenClear(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (*(int *)(child + 4) != 0) return;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov282_AiEnterIdle);
}
