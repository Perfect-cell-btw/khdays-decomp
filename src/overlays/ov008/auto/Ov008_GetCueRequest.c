extern int data_ov008_02090f04[];
int Ov008_GetCueRequest(void)
{
    return data_ov008_02090f04[1] + 0x9740;
}
