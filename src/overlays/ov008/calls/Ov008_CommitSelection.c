extern char *data_ov008_02090fac;
extern int Ov008_FindNewlyEarnedReward(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_CloseBuyDialog(void);
extern void Ov008_Shop_OpenBuy(void);
extern void Ov008_RebuildTabList(void);

/* Commits the pending selection: on success hands over to the confirm screen, otherwise rewinds to
 * the list and flags it dirty. */
void *Ov008_CommitSelection(void) {
    char *st = *(char **)&data_ov008_02090fac + 0xc54c;
    *(int *)(st + 0x24) = Ov008_FindNewlyEarnedReward();
    Ov008_RefreshPanelDisplay();
    *(int *)(st + 0x20) = 0;
    if (*(int *)(st + 0x24) != 0) {
        return (void *)&Ov008_Shop_OpenBuy;
    }
    Ov008_CloseBuyDialog();
    *(int *)(*(char **)&data_ov008_02090fac + 0xc3d4) = 1;
    return (void *)&Ov008_RebuildTabList;
}
