/* Clears the two active handler slots. */

extern int data_ov008_02090f0c[];
void Ov008_ClearActiveHandlers(void)
{
    data_ov008_02090f0c[0] = -1;
    data_ov008_02090f0c[1] = -1;
}
