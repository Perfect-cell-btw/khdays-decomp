extern int *Ov008_GetPageB(void);

int Ov008_PageB_GetScrollRow(void)
{
    return Ov008_GetPageB()[0xb] >> 0xc;
}
