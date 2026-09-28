/* Returns the menu context's word at +0x1408, or -1 without a context. */

extern int Ov008_GetMenuContext(void);
int Ov008_GetMenuField1408(void)
{
    int base = Ov008_GetMenuContext();
    if (base != 0) {
        return *(int *)(base + 0x1408);
    }
    return -1;
}
