/* First canned descriptor of the screen work area (+0x9680). */

extern int data_ov008_02090f04[];
int Ov008_GetDescriptor0(void)
{
    return data_ov008_02090f04[1] + 0x9680;
}
