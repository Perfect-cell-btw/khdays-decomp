/* Count the +0x1c timer up; past 0x2aa bump +0x398 by 0x400 and dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_AiPulseEnd(int);
void Ov253_AiPulseTick(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(owner + 0x1c) + *(int *)(a + 0x2c);
    *(int *)(owner + 0x1c) = t;
    if (t < 0x2aa) return;
    *(int *)(*(int *)owner + 0x398) += 0x400;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_AiPulseEnd);
}
