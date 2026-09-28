extern int data_ov008_02090f0c[];

void Ov008_ResetActiveHandlers(void)
{
    if (data_ov008_02090f0c[0] != -1) {
        data_ov008_02090f0c[0] = -1;
    }

    if (data_ov008_02090f0c[1] != -1) {
        data_ov008_02090f0c[1] = -1;
    }
}
