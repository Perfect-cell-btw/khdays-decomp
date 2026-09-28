/* Ov025_ScrollPanelToRow -- scroll the ov025 list to row param_1 (needs at least 11 rows).
 * Records the requested row at ctx+0x5c, clamps it to [0, rows-10], maps it through
 * func_02020400 over the visible span ((0x14 - ctx+0x60) * 8) and slides the view
 * (Ov025_Reports_PlaceRows) from the base at ctx+0x64. */
extern int  Ov025_GetPageA(void);
extern int  func_02020400(int a, int b);
extern void Ov025_Reports_PlaceRows(int to, int from);

void Ov025_ScrollPanelToRow(int param_1) {
    int ctx = Ov025_GetPageA();
    int span;
    if (*(int *)(ctx + 0x58) <= 10) {
        return;
    }
    *(int *)(ctx + 0x5c) = param_1;
    span = *(int *)(ctx + 0x58) - 10;
    if (param_1 < 0) {
        param_1 = 0;
    }
    if (param_1 > span) {
        param_1 = span;
    }
    {
        int off = func_02020400(param_1 * ((0x14 - *(int *)(ctx + 0x60)) * 8), span);
        Ov025_Reports_PlaceRows(*(int *)(ctx + 0x64) + off, *(int *)(ctx + 0x64));
    }
}
