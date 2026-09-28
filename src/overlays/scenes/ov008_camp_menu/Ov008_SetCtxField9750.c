/* Stores the menu state's byte at +0x9750. */

extern int data_ov008_02090f04[];
void Ov008_SetCtxField9750(int value)
{
    *(unsigned char *)(data_ov008_02090f04[1] + 0x9750) = value;
}
