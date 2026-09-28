/* Per-frame update: sets the widget's tag, advances the effect slot and draws it. */

extern void Widget_SetTagWord(int a, int b);
extern void Ov100_StepEffectSlot(int a, int b, int c);
extern void Ov100_ForwardArg1IfStateInRangeAndFlag(int a, int b);
extern int data_ov100_020bc1c0;

void Ov100_SetupTwoSubActionsWithGlobal(int this_) {
    int dv = data_ov100_020bc1c0;
    char *b = (char *)(dv + 0xdf0);
    Widget_SetTagWord(dv + 0x2c30, *(unsigned short *)(this_ + 0xeb0));
    Ov100_StepEffectSlot(this_, (int)(b + 0x2000), *(short *)(this_ + 0x2aba));
    Ov100_ForwardArg1IfStateInRangeAndFlag(this_, (int)(b + 0x2000));
}
