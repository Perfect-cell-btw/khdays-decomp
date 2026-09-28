extern int data_ov008_02090f04[];
void Ov008_SetCtxField962c(int value)
{
    *(int *)(data_ov008_02090f04[1] + 0x962c) = value == 0;
}
