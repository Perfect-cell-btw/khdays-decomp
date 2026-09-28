/* Run 020d0878, reset the motion fields, then dispatch via c634. */
extern int SetIndexedSlot(int, int, void *);
extern int Ov238_TargetGap(int);
extern int Ov238_AiComboStart(int);
void Ov238_AiEnterCombo(int param_1) {
    int owner = *(int *)(param_1 + 4);
    Ov238_TargetGap(param_1);
    *(int *)(owner + 0x20) = 0;
    *(signed char *)(owner + 0x2d) = 0;
    *(signed char *)(owner + 0x2e) = 1;
    *(signed char *)(owner + 0x31) = 4;
    SetIndexedSlot(param_1, *(signed char *)(param_1 + 0x20), (void *)&Ov238_AiComboStart);
}
