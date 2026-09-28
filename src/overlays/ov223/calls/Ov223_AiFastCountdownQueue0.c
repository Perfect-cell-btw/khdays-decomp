/* Tick the owner's +0x40 timer by double-rate; on expiry reset it, mark state 0 and dispatch. */
extern int SetIndexedSlot(int, int, int);
void Ov223_AiFastCountdownQueue0(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(owner + 0x40) - *(int *)(a + 0x2c) * 2;
    *(int *)(owner + 0x40) = t;
    if (t > 0) return;
    *(int *)(owner + 0x40) = 0;
    *(signed char *)(*(int *)owner + 0x1c7) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
