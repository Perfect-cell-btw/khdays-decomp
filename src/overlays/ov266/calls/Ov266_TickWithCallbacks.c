/* Finalize the list at (param_1)+0x388 with param_2, re-init it, then run the ov107 attach. */
extern void RefreshObjectCallbacks(int a, int b);
extern void DispatchObjectCallbacks(int a, int b);
extern void Ov107_ProcessObjectTick(int a, int b);
void Ov266_TickWithCallbacks(int param_1, int param_2) {
    RefreshObjectCallbacks(*(int *)(param_1 + 0x388), param_2);
    DispatchObjectCallbacks(*(int *)(param_1 + 0x388), 1);
    Ov107_ProcessObjectTick(param_1, param_2);
}
