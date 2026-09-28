extern char *Ov025_GetPageB(void);
int Ov025_PageB_GetScrollRow(void)
{
    return *(int *)(Ov025_GetPageB() + 44) >> 12;
}
