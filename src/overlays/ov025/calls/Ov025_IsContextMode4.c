extern int Ov025_GetContext_2(void);
int Ov025_IsContextMode4(void)
{
    return Ov025_GetContext_2() == 4;
}
