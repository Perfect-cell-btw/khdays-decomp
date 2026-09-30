/* Count the +0x40 timer up; past 0x3000 clear the child gate and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov245_Rider_AiEndPause(int);
void Ov245_Rider_AiPauseTick(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(owner + 0x40) + *(int *)(a + 0x2c);
    *(int *)(owner + 0x40) = t;
    if (t <= 0x3000) return;
    *(signed char *)(*(int *)(owner + 4) + 0xa8) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov245_Rider_AiEndPause);
}
