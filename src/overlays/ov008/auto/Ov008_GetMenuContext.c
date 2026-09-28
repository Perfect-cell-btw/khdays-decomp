/* Return the first of the two page objects held by the ov008 menu context (ctx =
 * data_ov008_02090f04[1], field +0x959c). Ov008_UpdateInputAndEnterMode3 ticks it every frame with
 * Ov008_HandlerA_Call2, alongside Ov008_GetPageB and Ov008_HandlerB_Call2. ov025 keeps the same
 * context layout -- see Ov025_GetPageA. */

extern int data_ov008_02090f04[];
int Ov008_GetMenuContext(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x959c);
}
