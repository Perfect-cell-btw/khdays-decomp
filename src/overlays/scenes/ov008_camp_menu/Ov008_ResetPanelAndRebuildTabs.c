/* Hides the detail overlay, redraws both columns and the panel, clears +0xc3d4 and returns the
 * tab-list rebuild step. */

extern char *data_ov008_02090fac;
extern void Ov008_HideDetailOverlay(void);
extern void Ov008_RedrawBothColumns(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_RebuildTabList(void);

void (*Ov008_ResetPanelAndRebuildTabs(void))(void)
{
    Ov008_HideDetailOverlay();
    Ov008_RedrawBothColumns();
    Ov008_RefreshPanelDisplay();
    *(int *)(data_ov008_02090fac + 0xc3d4) = 0;
    return Ov008_RebuildTabList;
}
