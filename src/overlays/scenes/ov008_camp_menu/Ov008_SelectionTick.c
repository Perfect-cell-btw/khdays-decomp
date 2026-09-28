extern char *data_ov008_02090fac;
extern void Ov008_HideShopList(void);
extern int Ov008_FindEntryById(void *p, int a);
extern void Ov008_SetEntrySlotsVisible(void *p, int a, int b);
extern void Ov008_HideCounterPanel(void);
extern void Ov008_RefreshPanelDisplay(void);
extern void Ov008_EnterSelectionScreen(void);

/* Per-frame tick: keeps the highlighted entry's sound playing, resets the fade counter when we are
 * about to re-enter the screen, and returns the next state. */
void *Ov008_SelectionTick(void) {
    char *st = *(char **)&data_ov008_02090fac;
    char **list;
    Ov008_HideShopList();
    if (*(int *)(st + 0xc250) == 2) {
        list = *(char ***)(st + 0xc3d0);
        if (list != 0) {
            if (*(unsigned int *)(*(char **)(list[*(int *)(st + 0xc3c4)] + 0xc) + 0x24) < 0x3f) {
                Ov008_SetEntrySlotsVisible(*(char **)&data_ov008_02090fac + 0x2ab0,
                    Ov008_FindEntryById(*(char **)&data_ov008_02090fac + 0x2ab0, 0x3f), 1);
            }
        }
    }
    if (*(void **)(st + 0xc3d8) == (void *)&Ov008_EnterSelectionScreen) {
        Ov008_HideCounterPanel();
        *(int *)st = 0;
    }
    Ov008_RefreshPanelDisplay();
    return *(void **)(st + 0xc3d8);
}
