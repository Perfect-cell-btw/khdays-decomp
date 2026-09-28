extern char *data_ov008_02090f24;
int Ov008_GetMissionOptionMask(void)
{
    if (data_ov008_02090f24 != 0) {
        return *(unsigned short *)(data_ov008_02090f24 + 0x434);
    }
    return 0;
}
