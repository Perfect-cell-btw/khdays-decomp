extern int data_ov008_02090f04[];
int Ov008_GetCtxWord9758(int index)
{
    return *(int *)(data_ov008_02090f04[1] + index * 4 + 0x9758);
}
