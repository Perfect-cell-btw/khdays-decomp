/* Force the first ov008 id word to -1 and return 1. */

extern int data_ov008_02090f0c[];
int Ov008_ClearHandlerA(void)
{
    if (data_ov008_02090f0c[0] != -1) {
        data_ov008_02090f0c[0] = -1;
    }
    return 1;
}
