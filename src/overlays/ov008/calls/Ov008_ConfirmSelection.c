extern char *data_ov008_02090fac;
extern void Ov008_Shop_HideRows(void);
extern void Ov008_RefreshPanelDisplay(void);
extern int Ov008_FindNewlyEarnedReward(void);
extern void Ov008_Shop_OpenBuy(void);
extern void Ov008_RebuildTabList(void);

/* Confirms the current selection. Only tab 3 can produce a result worth going to the confirm
 * screen for; everything else falls back to the list. */
void *Ov008_ConfirmSelection(void) {
    char *st = *(char **)&data_ov008_02090fac;
    int result;
    Ov008_Shop_HideRows();
    Ov008_RefreshPanelDisplay();
    *(int *)(st + 0xc56c) = 1;
    if (*(int *)(st + 0xc250) == 3) {
        result = Ov008_FindNewlyEarnedReward();
        *(int *)(st + 0xc570) = result;
        if (result != 0) {
            *(int *)(st + 0xc568) = 1;
            return (void *)&Ov008_Shop_OpenBuy;
        }
    }
    *(int *)(st + 0xc3d4) = 1;
    return (void *)&Ov008_RebuildTabList;
}
