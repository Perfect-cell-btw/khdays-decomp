/* Clear +4/+8; dispatch to one of two handlers depending on whether +0xc is set. */
extern int SetIndexedSlot(int a, int b, void *handler);
extern void Ov119_TimerBlinkParityClear(int);
extern void Ov119_TimerBlinkParitySet(int);
void Ov119_TimerBlinkStart(int param_1) {
    int child = *(int *)(param_1 + 4);
    *(int *)(child + 4) = 0;
    *(int *)(child + 8) = 0;
    if (*(int *)(child + 0xc) == 0)
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov119_TimerBlinkParityClear);
    else
        SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov119_TimerBlinkParitySet);
}
