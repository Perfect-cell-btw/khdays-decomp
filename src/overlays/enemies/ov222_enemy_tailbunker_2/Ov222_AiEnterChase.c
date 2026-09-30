/* Notify Ov222_SetModeAndResetCounters with the child fields, clear its flags at +0x75/+0x76, then
 * dispatch via SetIndexedSlot (handler Ov222_AiChaseTick). */
extern void Ov222_SetModeAndResetCounters(int a, int b);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov222_AiChaseTick(void);
void Ov222_AiEnterChase(int param_1) {
    int child = *(int *)(param_1 + 4);
    Ov222_SetModeAndResetCounters(*(int *)child, *(int *)(child + 0x78));
    *(unsigned char *)(child + 0x75) = 0;
    *(unsigned char *)(child + 0x76) = 0;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov222_AiChaseTick);
}
