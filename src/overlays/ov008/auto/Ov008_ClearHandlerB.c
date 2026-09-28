extern int data_ov008_02090f0c[];
int Ov008_ClearHandlerB(void)
{
    if (data_ov008_02090f0c[1] != -1) {
        data_ov008_02090f0c[1] = -1;
    }
    return 1;
}
