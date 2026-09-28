/* Set the word at +0x9614 of the second ov008 global object to 1. */

extern int data_ov008_02090f04[];
void Ov008_SetCtxField9614(void)
{
    *(int *)(data_ov008_02090f04[1] + 0x9614) = 1;
}
