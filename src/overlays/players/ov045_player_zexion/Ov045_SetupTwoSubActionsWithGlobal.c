/* Per-frame update: sets the widget's tag, advances the effect slot and draws it. */

extern void Widget_SetTagWord(int a, int b);
extern void Ov045_StepEffectSlot(int a, int b, int c);
extern void Ov045_ForwardArg1IfStateInRangeAndFlag(int a, int b);
extern int data_ov045_020b4c20;

void Ov045_SetupTwoSubActionsWithGlobal(int this_) {
    int dv = data_ov045_020b4c20;
    char *b = (char *)(dv + 0xdf0);
    Widget_SetTagWord(dv + 0x2c30, *(unsigned short *)(this_ + 0xeb0));
    Ov045_StepEffectSlot(this_, (int)(b + 0x2000), *(short *)(this_ + 0x2aba));
    Ov045_ForwardArg1IfStateInRangeAndFlag(this_, (int)(b + 0x2000));
}
