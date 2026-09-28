/* Forward (param_1, param_2) plus the pointer at (*global)+0x4b0 to the handler. */
extern int Ov002_LookupSlotEnabledBit(int a, int b, int c);
extern int data_ov002_0207f620;

int Ov002_Panel_IsSlotEnabledA(int param_1, int param_2) {
    return Ov002_LookupSlotEnabledBit(param_1, param_2, *(int *)(*(int *)&data_ov002_0207f620 + 0x4b0));
}
