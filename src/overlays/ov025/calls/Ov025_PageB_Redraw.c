/* Refreshes and redraws page B's rows. */

extern int Ov025_GetPageB();
extern int Ov025_GetCtxBlock954c();
extern int Ov025_RefreshPageBRow();
extern int Ov025_DrawPageBRows();

void Ov025_PageB_Redraw(void) {
    Ov025_GetPageB();
    Ov025_GetCtxBlock954c();
    Ov025_RefreshPageBRow();
    Ov025_DrawPageBRows();
}
