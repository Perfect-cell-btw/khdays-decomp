extern int data_ov008_02090f04[];
void Ov008_SetCtxField95cc(int value)
{
    *(int *)(data_ov008_02090f04[1] + 0x95cc) = value;
}
