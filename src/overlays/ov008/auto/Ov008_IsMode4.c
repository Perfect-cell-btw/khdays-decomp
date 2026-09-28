extern char *data_ov008_02090f04[];

int Ov008_IsMode4(void)
{
    char *base = data_ov008_02090f04[1];

    if (base == 0) {
        return 0;
    }

    return *(int *)(base + 0x95cc) == 4;
}
