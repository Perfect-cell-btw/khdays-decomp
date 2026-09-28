/* Tick +0x1c down; once expired clear the gate byte, and unless busy kick anim 0xa and dispatch. */
extern int Ov107_PostTagUpdate(int, int, int);
extern int SetIndexedSlot(int, int, void *);
extern int Ov253_ReviveTick(int);
void Ov253_AiDownCountdown(int param_1) {
    int a = *(int *)param_1;
    int owner = *(int *)(param_1 + 4);
    int t = *(int *)(owner + 0x1c) - *(int *)(a + 0x2c);
    *(int *)(owner + 0x1c) = t;
    if (t > 0) return;
    *(signed char *)(*(int *)(*(int *)owner + 0x38c) + 0xa8) = 0;
    if (*(unsigned char *)(*(int *)(owner + 4)) != 0) return;
    Ov107_PostTagUpdate(*(int *)owner, 0xa, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov253_ReviveTick);
}
