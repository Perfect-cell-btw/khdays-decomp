/* Return the object pointer stored at +0x9634 of the ov008 menu context. Ov025_GetCtxObject9634 is
 * the same field in ov025 -- the two overlays share this context layout. */

extern int data_ov008_02090f04[];
int Ov008_GetCtxObject9634(void)
{
    return *(int *)(data_ov008_02090f04[1] + 0x9634);
}
