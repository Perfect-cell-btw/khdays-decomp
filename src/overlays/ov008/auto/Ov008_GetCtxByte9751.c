extern int data_ov008_02090f04[];
int Ov008_GetCtxByte9751(int offset)
{
    return *(unsigned char *)(data_ov008_02090f04[1] + offset + 0x9751);
}
