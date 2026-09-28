/* Selects the current handler; returns 1. */

extern int data_ov008_02090f0c[];
int Ov008_SetHandlerA(int value)
{
    data_ov008_02090f0c[0] = value;
    return 1;
}
