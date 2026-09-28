extern char *data_ov026_02091368;
extern void Ov026_Shop_HideRows(void);
extern void Ov026_RefreshPanelDisplay(void);
extern int Ov026_FindNewlyEarnedReward(void);
extern void Ov026_Shop_OpenBuy(void);
extern void Ov026_RebuildTabList(void);

/* Confirms the current selection. Only tab 3 can produce a result worth going to the confirm
 * screen for; everything else falls back to the list. */
void *Ov026_ConfirmSelection(void) {
    char *st = *(char **)&data_ov026_02091368;
    int result;
    Ov026_Shop_HideRows();
    Ov026_RefreshPanelDisplay();
    *(int *)(st + 0xc56c) = 1;
    if (*(int *)(st + 0xc250) == 3) {
        result = Ov026_FindNewlyEarnedReward();
        *(int *)(st + 0xc570) = result;
        if (result != 0) {
            *(int *)(st + 0xc568) = 1;
            return (void *)&Ov026_Shop_OpenBuy;
        }
    }
    *(int *)(st + 0xc3d4) = 1;
    return (void *)&Ov026_RebuildTabList;
}
