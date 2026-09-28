extern int data_ov008_02090f04[];
void Ov008_SetCtxField9678(int value)
{
    *(int *)(data_ov008_02090f04[1] + 0x9678) = value;
}
