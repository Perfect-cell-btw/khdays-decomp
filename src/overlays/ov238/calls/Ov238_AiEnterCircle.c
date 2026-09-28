/* Clear +0x2c/+0x3c, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov238_CircleTick(int);
int Ov238_AiEnterCircle(int param_1) {
    int owner = *(int *)(param_1 + 4);
    *(int *)(owner + 0x2c) = 0;
    *(int *)(owner + 0x3c) = 0;
    return SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_CircleTick);
}
