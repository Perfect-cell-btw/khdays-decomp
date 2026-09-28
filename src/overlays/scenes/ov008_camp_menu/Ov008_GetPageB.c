extern int data_ov008_02090f04[];
int Ov008_GetPageB(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x95a0);
}
