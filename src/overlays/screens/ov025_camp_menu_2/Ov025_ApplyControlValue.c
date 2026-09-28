extern void Ov025_SetFlagBit0();
extern void Ov025_SetControlBit1AtA7C();
extern void Ov025_SetControlBit0AtA7C();
extern int data_ov025_020b5744;

void Ov025_ApplyControlValue(unsigned int arg0) {
    Ov025_SetFlagBit0(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9500, arg0);
    Ov025_SetControlBit1AtA7C(*(int *)((char *)&data_ov025_020b5744 + 4), arg0);
    Ov025_SetControlBit0AtA7C(*(int *)((char *)&data_ov025_020b5744 + 4), arg0);
    *(unsigned int *)(*(int *)((char *)&data_ov025_020b5744 + 4) + 0x9600) = arg0;
}
