/* Read the word at +0x95cc of the second ov008 global object. */

extern int data_ov008_02090f04[];
int Ov008_GetCtxField95cc(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x95cc);
}
