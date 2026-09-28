/* Store param into the second ov008 global word and return 1. */

extern int data_ov008_02090f0c[];
int Ov008_SetHandlerB(int value)
{
    data_ov008_02090f0c[1] = value;
    return 1;
}
