extern int *data_ov008_02090f00;
int Ov008_IsSessionReady(void)
{
    if (data_ov008_02090f00 != 0) {
        return data_ov008_02090f00[0];
    }
    return 0;
}
