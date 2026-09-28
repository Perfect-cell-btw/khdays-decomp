/* Count the +0x1c timer up; past 0x444 set +0x398=0x1000, reset it and dispatch. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AiShrinkWait(int);
void Ov253_AiShrinkTick(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(owner + 0x1c) + *(int *)(a + 0x2c);
    *(int *)(owner + 0x1c) = t;
    if (t < 0x444) return;
    *(int *)(*(int *)owner + 0x398) = 0x1000;
    *(int *)(owner + 0x1c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiShrinkWait);
}
