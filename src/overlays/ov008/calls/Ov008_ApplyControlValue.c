extern void Ov008_SetFlagBit0();
extern void Ov008_SetControlBit1AtA7C();
extern void Ov008_SetControlBit0AtA7C();
extern int data_ov008_02090f04;

void Ov008_ApplyControlValue(unsigned int arg0) {
    Ov008_SetFlagBit0(*(int *)((char *)&data_ov008_02090f04 + 4) + 0x9500, arg0);
    Ov008_SetControlBit1AtA7C(*(int *)((char *)&data_ov008_02090f04 + 4), arg0);
    Ov008_SetControlBit0AtA7C(*(int *)((char *)&data_ov008_02090f04 + 4), arg0);
    *(unsigned int *)(*(int *)((char *)&data_ov008_02090f04 + 4) + 0x9600) = arg0;
}
