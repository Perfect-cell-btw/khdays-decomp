/* For type 0x15 stores the value of parameter record index; returns 1. */

extern char *data_ov008_02090fb0;

int Ov008_GetParamRecordValue(int *out, int type, int index)
{
    if (type != 0x15) {
        return 0;
    }

    *out = *(int *)(*(char **)(data_ov008_02090fb0 + 0x14) + (index - 1) * 0x34 + 0xc);
    return 1;
}
