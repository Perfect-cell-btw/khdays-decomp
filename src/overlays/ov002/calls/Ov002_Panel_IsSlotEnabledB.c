extern int data_ov002_0207f620;
extern int Ov002_LookupSlotEnabledBit();

int Ov002_Panel_IsSlotEnabledB(int arg0, int arg1) {
    return Ov002_LookupSlotEnabledBit(arg0, (unsigned short)arg1, *(int *)(*(int *)&data_ov002_0207f620 + 0x4b4));
}
