extern char *data_ov008_02090fa4;
int Ov008_SetMissionCursorSelection(int value)
{
    if (data_ov008_02090fa4 == 0) {
        value = 0;
    } else {
        *(unsigned char *)(data_ov008_02090fa4 + 0x950c) = value;
        value = 1;
    }
    return value;
}
