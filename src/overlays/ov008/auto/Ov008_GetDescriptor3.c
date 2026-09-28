/* Fourth canned descriptor of the screen work area (+0x96a4). */

extern int data_ov008_02090f04[];
int Ov008_GetDescriptor3(void)
{
    return data_ov008_02090f04[1] + 0x96a4;
}
