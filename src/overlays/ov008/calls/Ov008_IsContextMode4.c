/* Whether the menu context is in mode 4. */

extern int Ov008_GetContext_2(void);
int Ov008_IsContextMode4(void)
{
    return Ov008_GetContext_2() == 4;
}
