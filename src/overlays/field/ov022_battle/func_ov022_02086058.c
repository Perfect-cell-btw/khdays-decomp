/* Frees the UI subsystem's six sprites, clears its selection and its tween. */

extern void Ov002_FreeBufferAndClearStatus(int arg0);
extern void Tween_Clear(unsigned int *arg0);

void func_ov022_02086058(int arg0) {
    int i = 0;
    int p = arg0;
    do {
        Ov002_FreeBufferAndClearStatus(p);
        i = i + 1;
        p = p + 0x30;
    } while (i < 4);
    {
        int p2;
        int i2;
        i2 = 0;
        p2 = arg0 + 0xc0;
        do {
            Ov002_FreeBufferAndClearStatus(p2);
            i2 = i2 + 1;
            p2 = p2 + 0x30;
        } while (i2 < 2);
    }
    *(int *)(arg0 + 0x124) = 0;
    *(int *)(arg0 + 0x128) = 0;
    Tween_Clear((unsigned int *)(arg0 + 300));
}
