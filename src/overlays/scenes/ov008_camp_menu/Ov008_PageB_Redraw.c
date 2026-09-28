/* Refreshes and redraws page B's rows. */

extern void Ov008_GetPageB(void);
extern void Ov008_GetCtxBlock954c(void);
extern void Ov008_RefreshPageBRow(void);
extern void Ov008_DrawPageBRows(void);
void Ov008_PageB_Redraw(void)
{
    Ov008_GetPageB();
    Ov008_GetCtxBlock954c();
    Ov008_RefreshPageBRow();
    Ov008_DrawPageBRows();
}
