/* Whether the menu context is in mode 4. */

extern int Ov025_GetContext_2(void);
int Ov025_IsContextMode4(void)
{
    return Ov025_GetContext_2() == 4;
}
