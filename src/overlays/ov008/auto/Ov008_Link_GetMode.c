extern char *data_ov008_02090f24;
int Ov008_Link_GetMode(void)
{
    return *(unsigned char *)(data_ov008_02090f24 + 0x100);
}
