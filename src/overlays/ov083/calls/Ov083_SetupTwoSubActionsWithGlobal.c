extern void Widget_SetTagWord(int a, int b);
extern void Ov083_StepEffectSlot(int a, int b, int c);
extern void Ov083_ForwardArg1IfStateInRangeAndFlag(int a, int b);
extern int data_ov083_020b9b00;

void Ov083_SetupTwoSubActionsWithGlobal(int this_) {
    int dv = data_ov083_020b9b00;
    char *b = (char *)(dv + 0xdf0);
    Widget_SetTagWord(dv + 0x2c30, *(unsigned short *)(this_ + 0xeb0));
    Ov083_StepEffectSlot(this_, (int)(b + 0x2000), *(short *)(this_ + 0x2aba));
    Ov083_ForwardArg1IfStateInRangeAndFlag(this_, (int)(b + 0x2000));
}
