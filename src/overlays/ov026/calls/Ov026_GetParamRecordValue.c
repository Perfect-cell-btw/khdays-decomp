extern char *data_ov026_0209136c;

int Ov026_GetParamRecordValue(int *out, int type, int index)
{
    if (type != 0x15) {
        return 0;
    }

    *out = *(int *)(*(char **)(data_ov026_0209136c + 0x14) + (index - 1) * 0x34 + 0xc);
    return 1;
}
