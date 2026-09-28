extern int data_ov008_02090f04[];
void Ov008_SetCtxWord9758(int index, int value)
{
    *(int *)(data_ov008_02090f04[1] + index * 4 + 0x9758) = value;
}
