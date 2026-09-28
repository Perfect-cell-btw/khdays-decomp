/* If Ov225_MeasureTargetGap fails (<0), dispatch with a null handler and return;
 * else set anim (8 if child+0x78 else 0xc), clear +0x76/+0x75/+0x5c, dispatch. */
extern int Ov225_MeasureTargetGap(int a, int b);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov225_ChargeWindupTick(void);
void Ov225_AiEnterChargeWindup(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (Ov225_MeasureTargetGap(param_1, 0) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
        return;
    }
    Ov107_PostTagUpdate(*(int *)child, *(int *)(child + 0x78) != 0 ? 8 : 0xc, 0);
    *(unsigned char *)(child + 0x76) = 0;
    *(unsigned char *)(child + 0x75) = 0;
    *(int *)(child + 0x5c) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov225_ChargeWindupTick);
}
