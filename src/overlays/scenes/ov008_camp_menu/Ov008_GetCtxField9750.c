extern int data_ov008_02090f04[];
int Ov008_GetCtxField9750(void)
{
    return *(unsigned char *)(data_ov008_02090f04[1] + 0x9750);
}
