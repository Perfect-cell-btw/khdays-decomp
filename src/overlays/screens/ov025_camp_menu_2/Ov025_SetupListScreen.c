extern char *Ov025_GetPageA(void);
extern void Ov025_PageA_ResetLarge(void);
extern void Ov025_Tutorial_SetupDisplay(void);
extern int Ov025_GetCtxBlock9500(void);
extern int Ov025_GetContext(void);
extern void Ov025_Tutorial_LoadBackground(void);
extern void Ov025_Tutorial_SetupEntries(void);
extern void Ov025_Tutorial_SetupSurfaces(void);
extern void Ov025_ResolveListRowIds(void);
extern void Ov025_Tutorial_BuildTopicList(void);
extern void Ov025_Tutorial_SetupList(int page);
extern void Ov025_Tutorial_Refresh(void);
extern void Ov025_ArmCueRequest(int node, int a, int b);

/* Brings the list screen up: caches the two active objects, initialises every widget, selects
 * the current row and moves the state field to 1. */
int Ov025_SetupListScreen(void) {
    char *self = Ov025_GetPageA();
    Ov025_PageA_ResetLarge();
    Ov025_Tutorial_SetupDisplay();
    *(int *)(self + 0xc4) = Ov025_GetCtxBlock9500();
    *(int *)(self + 0xc8) = Ov025_GetContext();
    Ov025_Tutorial_LoadBackground();
    Ov025_Tutorial_SetupEntries();
    Ov025_Tutorial_SetupSurfaces();
    Ov025_ResolveListRowIds();
    Ov025_Tutorial_BuildTopicList();
    Ov025_Tutorial_SetupList(*(short *)(self + 4));
    Ov025_Tutorial_Refresh();
    Ov025_ArmCueRequest(*(int *)(self + *(short *)(self + 2) * 8 + 0xd0), 0, 0);
    *(int *)(self + 0xc) = (*(int *)(self + 0xc) & ~0xf0) | 0x10;
    return 1;
}
