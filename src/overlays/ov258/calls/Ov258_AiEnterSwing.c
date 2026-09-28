/* Clear +0xc/+0x10, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov258_SwingTick_2(int);
int Ov258_AiEnterSwing(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0xc) = 0;
    *(signed char *)(owner + 0x10) = 0;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov258_SwingTick_2);
}
