extern char *data_ov008_02090f24;
int Ov008_Link_IsLocal(void)
{
    if (data_ov008_02090f24 != 0) {
        return *(int *)(data_ov008_02090f24 + 0x4e8);
    }
    return 1;
}
