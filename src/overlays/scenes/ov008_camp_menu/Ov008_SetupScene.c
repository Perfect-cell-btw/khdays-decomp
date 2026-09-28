extern void Ov008_Menu_ApplyFlagPresets(char *self, int mode, int *out);
extern void Ov008_InitPanel(char *self, int *cfg);
extern void Ov008_SetupSceneDisplay(void);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void Ov008_VarTable_Load(char *p, void *tbl);
extern void Ov008_SetupMenuBgCells(void);
extern void Ov008_SetupMenuSurfaces(char *self);
extern void func_ov008_020593cc(char *self);
extern void Ov008_PushCountersToEventFlags(void);
extern void Ov008_Menu_RefreshSubitemGrid(void);
extern void Ov008_Menu_RefreshSlotPanel(void);
extern void Ov008_Menu_InitSceneObject(char *p, int *cfg);
extern int data_ov008_020901fc;

/* Scene setup: builds the empty layout descriptor, marks the slot unused, blanks the three
 * tiled BG screens and brings up every sub-system. */
int Ov008_SetupScene(char *self) {
    int cfg[4] = { 0, 0, 0, 0 };
    Ov008_Menu_ApplyFlagPresets(self, 0, cfg);
    *(int *)(self + 0x88) = -1;
    Ov008_InitPanel(self, cfg);
    Ov008_SetupSceneDisplay();
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    Ov008_VarTable_Load(self + 4, &data_ov008_020901fc);
    Ov008_SetupMenuBgCells();
    Ov008_SetupMenuSurfaces(self);
    func_ov008_020593cc(self);
    Ov008_PushCountersToEventFlags();
    Ov008_Menu_RefreshSubitemGrid();
    Ov008_Menu_RefreshSlotPanel();
    Ov008_Menu_InitSceneObject(self + 0x98, cfg);
    return 1;
}
