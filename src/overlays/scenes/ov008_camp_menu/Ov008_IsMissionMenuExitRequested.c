extern char *data_ov008_02090f24;
int Ov008_IsMissionMenuExitRequested(void)
{
    return *(unsigned char *)(data_ov008_02090f24 + 0x4ef);
}
