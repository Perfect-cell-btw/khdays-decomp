/* Third canned descriptor of the screen work area (+0x9698). */

extern int data_ov008_02090f04[];
int Ov008_GetDescriptor2(void)
{
    return data_ov008_02090f04[1] + 0x9698;
}
