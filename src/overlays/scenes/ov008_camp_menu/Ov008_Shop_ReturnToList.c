/* Refreshes the detail panel, both columns and the display, clears the dialog flag and returns the
 * list step. */

extern char *data_ov008_02090fac;
extern void Ov008_RefreshDetailPanel(void);
extern void Ov008_RedrawBothColumns(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_RebuildTabList(void);

void (*Ov008_Shop_ReturnToList(void))(void)
{
    Ov008_RefreshDetailPanel();
    Ov008_RedrawBothColumns();
    Ov008_RefreshPanelDisplay();
    *(int *)(data_ov008_02090fac + 0xc3d4) = 0;
    return Ov008_RebuildTabList;
}
