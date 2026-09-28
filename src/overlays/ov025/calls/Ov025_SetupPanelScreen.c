extern char *Ov025_GetPageA(void);
extern void Ov025_Reports_InitPage(void);
extern void Ov025_Reports_SetupDisplay(void);
extern int Ov025_GetCtxBlock9500(void);
extern int Ov025_GetContext(void);
extern void Ov025_Reports_LoadPalette(void);
extern void Ov025_Reports_SetupEntries(void);
extern void Ov025_Reports_SetupSurface(void);
extern void Ov025_ResolvePanelRowIds(void);
extern void Ov025_Reports_LoadEntries(void);
extern void Ov025_Reports_CountUnlocked(void);
extern void Ov025_Reports_RefreshRowEntries(void);
extern void Ov025_Reports_SetupList(int page);
extern void Ov025_Reports_RefreshCurrentEntry(void);

/* Brings the panel screen up: caches the two active objects and initialises every widget. */
int Ov025_SetupPanelScreen(void) {
    char *self = Ov025_GetPageA();
    Ov025_Reports_InitPage();
    Ov025_Reports_SetupDisplay();
    *(int *)(self + 0xb4) = Ov025_GetCtxBlock9500();
    *(int *)(self + 0xb8) = Ov025_GetContext();
    Ov025_Reports_LoadPalette();
    Ov025_Reports_SetupEntries();
    Ov025_Reports_SetupSurface();
    Ov025_ResolvePanelRowIds();
    Ov025_Reports_LoadEntries();
    Ov025_Reports_CountUnlocked();
    Ov025_Reports_RefreshRowEntries();
    Ov025_Reports_SetupList(*(short *)(self + 4));
    Ov025_Reports_RefreshCurrentEntry();
    return 1;
}
