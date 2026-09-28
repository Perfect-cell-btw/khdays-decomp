/* Per-frame update: sets the widget's tag, advances the effect slot and draws it. */

extern void Widget_SetTagWord(int a, int b);
extern void Ov064_StepEffectSlot(int a, int b, int c);
extern void Ov064_ForwardArg1IfStateInRangeAndFlag(int a, int b);
extern int data_ov064_020b7420;

void Ov064_SetupTwoSubActionsWithGlobal(int this_) {
    int dv = data_ov064_020b7420;
    char *b = (char *)(dv + 0xdf0);
    Widget_SetTagWord(dv + 0x2c30, *(unsigned short *)(this_ + 0xeb0));
    Ov064_StepEffectSlot(this_, (int)(b + 0x2000), *(short *)(this_ + 0x2aba));
    Ov064_ForwardArg1IfStateInRangeAndFlag(this_, (int)(b + 0x2000));
}
