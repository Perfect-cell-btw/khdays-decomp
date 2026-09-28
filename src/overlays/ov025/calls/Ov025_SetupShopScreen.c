extern char *Ov025_GetPageB(void);
extern char *Ov025_GetCueRequest(void);
extern void Ov025_ApplyControlValue(int a);
extern void Ov025_SetActivePage(int a);
extern void Ov025_OpenTutorialPage(void);
extern int Msg_OpenContainerAndReadHeader(void *name, int slot);
extern void Ov025_LoadMenuSubBg2(int a);
extern void Ov025_InitTutorialSurfaces(void);
extern void Ov025_PlaceTutorialSurfaces(void);
extern void Ov025_PageB_Redraw(void);
extern int data_ov025_020b56bc;
extern int data_ov025_020b56d0;

/* Brings the shop screen up: republishes the current entry, loads the two sprite sets and
 * initialises the widgets. */
int Ov025_SetupShopScreen(void) {
    char *self = Ov025_GetPageB();
    Ov025_ApplyControlValue(*(int *)(Ov025_GetCueRequest() + 0xc));
    Ov025_SetActivePage(*(int *)(Ov025_GetCueRequest() + 0xc) == 0);
    Ov025_OpenTutorialPage();
    *(int *)(self + 0x30) = Msg_OpenContainerAndReadHeader(&data_ov025_020b56bc, 0xe);
    *(int *)(self + 0x34) = Msg_OpenContainerAndReadHeader(&data_ov025_020b56d0, 0xe);
    Ov025_LoadMenuSubBg2(1);
    Ov025_InitTutorialSurfaces();
    Ov025_PlaceTutorialSurfaces();
    Ov025_PageB_Redraw();
    return 1;
}
