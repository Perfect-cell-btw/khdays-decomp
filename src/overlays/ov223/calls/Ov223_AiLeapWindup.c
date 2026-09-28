/* If Ov223_MeasureTargetGap fails (<0), dispatch with a null handler and return.
 * Otherwise, unless the grandchild is busy (+0xad), set anim 0x14 and dispatch. */
extern int Ov223_MeasureTargetGap(int a, int b);
extern void Ov107_PostTagUpdate(int a, int b, int c);
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov223_LeapTick(void);
void Ov223_AiLeapWindup(int param_1) {
    int child = *(int *)(param_1 + 4);
    if (Ov223_MeasureTargetGap(param_1, 0) < 0) {
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)0);
        return;
    }
    if (*(unsigned char *)(*(int *)(child + 4) + 0xad) != 0) return;
    Ov107_PostTagUpdate(*(int *)child, 0x14, 0);
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov223_LeapTick);
}
