/* Tick the +0x14 timer down, spawn the child; once present and expired mark state 0xa. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov107_FindNearestObject(int, int);
void Ov278_AiSeekTick_2(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x14) = *(int *)(owner + 0x14) - *(int *)(a + 0x2c);
    int child = Ov107_FindNearestObject(*(int *)owner, 0);
    *(int *)(owner + 4) = child;
    if (child == 0) return;
    if (*(int *)(owner + 0x14) > 0) return;
    *(signed char *)(*(int *)owner + 0x1c7) = 0xa;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), 0);
}
