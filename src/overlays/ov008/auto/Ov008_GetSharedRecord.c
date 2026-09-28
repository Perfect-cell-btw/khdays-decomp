extern char *data_ov008_02090f00;
char *Ov008_GetSharedRecord(void)
{
    if (data_ov008_02090f00 != 0) {
        return data_ov008_02090f00 + 0x46;
    }
    return 0;
}
