/* Store a word at +0x95cc of the second ov008 global object. */

extern int data_ov008_02090f04[];
void Ov008_SetCtxField95cc(int value)
{
    *(int *)(data_ov008_02090f04[1] + 0x95cc) = value;
}
