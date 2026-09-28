extern void Ov008_EnableBothHalves(void);
extern int data_ov008_02090f04[];
void Ov008_SetCtxField95fc(int value)
{
    Ov008_EnableBothHalves();
    *(int *)(data_ov008_02090f04[1] + 0x95fc) = value;
}
