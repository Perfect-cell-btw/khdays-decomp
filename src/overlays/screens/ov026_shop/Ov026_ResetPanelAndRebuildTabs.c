/* Hides the detail overlay, redraws both columns and the panel, clears +0xc3d4 and returns the
 * tab-list rebuild step. */

extern char *data_ov026_02091368;
extern void Ov026_HideDetailOverlay(void);
extern void Ov026_RedrawBothColumns(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_RebuildTabList(void);

void (*Ov026_ResetPanelAndRebuildTabs(void))(void)
{
    Ov026_HideDetailOverlay();
    Ov026_RedrawBothColumns();
    Ov026_RefreshPanelDisplay();
    *(int *)(data_ov026_02091368 + 0xc3d4) = 0;
    return Ov026_RebuildTabList;
}
