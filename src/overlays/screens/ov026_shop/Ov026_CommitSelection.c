extern char *data_ov026_02091368;
extern int Ov026_FindNewlyEarnedReward(void);
extern void Ov026_RefreshPanelDisplay(void);
extern void Ov026_CloseBuyDialog(void);
extern void Ov026_Shop_OpenBuy(void);
extern void Ov026_RebuildTabList(void);

/* Commits the pending selection: on success hands over to the confirm screen, otherwise rewinds to
 * the list and flags it dirty. */
void *Ov026_CommitSelection(void) {
    char *st = *(char **)&data_ov026_02091368 + 0xc54c;
    *(int *)(st + 0x24) = Ov026_FindNewlyEarnedReward();
    Ov026_RefreshPanelDisplay();
    *(int *)(st + 0x20) = 0;
    if (*(int *)(st + 0x24) != 0) {
        return (void *)&Ov026_Shop_OpenBuy;
    }
    Ov026_CloseBuyDialog();
    *(int *)(*(char **)&data_ov026_02091368 + 0xc3d4) = 1;
    return (void *)&Ov026_RebuildTabList;
}
