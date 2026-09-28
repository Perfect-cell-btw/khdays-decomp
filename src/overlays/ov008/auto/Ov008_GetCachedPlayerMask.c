extern char *data_ov008_02090f00;
int Ov008_GetCachedPlayerMask(void)
{
    if (data_ov008_02090f00 != 0) {
        return *(unsigned short *)(data_ov008_02090f00 + 0x2c);
    }
    return 0;
}
