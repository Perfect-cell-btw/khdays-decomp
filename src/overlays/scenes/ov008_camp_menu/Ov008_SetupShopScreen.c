extern char *Ov008_GetPageB(void);
extern char *Ov008_GetCueRequest(void);
extern void Ov008_ApplyControlValue(int a);
extern void Ov008_SetActivePage(int a);
extern void Ov008_OpenTutorialPage(void);
extern int Msg_OpenContainerAndReadHeader(void *name, int slot);
extern void Ov008_LoadMenuSubBg2(int a);
extern void Ov008_InitTutorialSurfaces(void);
extern void Ov008_PlaceTutorialSurfaces(void);
extern void Ov008_PageB_Redraw(void);
extern int gOv008UiBtlttrTtrPath_2;
extern int gOv008UiBtlttrTtrPath_3;

/* Brings the shop screen up: republishes the current entry, loads the two sprite sets and
 * initialises the widgets. */
int Ov008_SetupShopScreen(void) {
    char *self = Ov008_GetPageB();
    Ov008_ApplyControlValue(*(int *)(Ov008_GetCueRequest() + 0xc));
    Ov008_SetActivePage(*(int *)(Ov008_GetCueRequest() + 0xc) == 0);
    Ov008_OpenTutorialPage();
    *(int *)(self + 0x30) = Msg_OpenContainerAndReadHeader(&gOv008UiBtlttrTtrPath_2, 0xe);
    *(int *)(self + 0x34) = Msg_OpenContainerAndReadHeader(&gOv008UiBtlttrTtrPath_3, 0xe);
    Ov008_LoadMenuSubBg2(1);
    Ov008_InitTutorialSurfaces();
    Ov008_PlaceTutorialSurfaces();
    Ov008_PageB_Redraw();
    return 1;
}
