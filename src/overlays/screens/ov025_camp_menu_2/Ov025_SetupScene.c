extern void Ov025_Menu_ApplyFlagPresets(char *self, int mode, int *cfg);
extern void Ov025_Hub_SetupGraphics(void);
extern void *G2_GetBG1ScrPtr(void);
extern void *G2_GetBG2ScrPtr(void);
extern void *G2_GetBG3ScrPtr(void);
extern void MIi_CpuClearFast(int value, void *dst, unsigned size);
extern void Ov025_InitResourceRecord(char *p, void *tbl);
extern void Ov025_LoadPageBackground(void);
extern void Ov025_Hub_SetupTextSurfaces(char *self);
extern void Ov025_Hub_InitializeWidgets(char *self);
extern void Ov025_PushCountersToEventFlags(void);
extern void Ov025_ModelActor_Init(char *p, int *cfg);
extern int gOv025UiCmStrRootTextPath;

/* Scene setup: builds the empty layout descriptor, marks the slot unused, blanks the three tiled
 * BG screens and brings up every sub-system. */
int Ov025_SetupScene(char *self) {
    int cfg[4] = { 0, 0, 0, 0 };
    Ov025_Menu_ApplyFlagPresets(self, 0, cfg);
    *(int *)(self + 0x88) = -1;
    Ov025_Hub_SetupGraphics();
    MIi_CpuClearFast(0, G2_GetBG1ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG2ScrPtr(), 0x800);
    MIi_CpuClearFast(0, G2_GetBG3ScrPtr(), 0x800);
    Ov025_InitResourceRecord(self + 4, &gOv025UiCmStrRootTextPath);
    Ov025_LoadPageBackground();
    Ov025_Hub_SetupTextSurfaces(self);
    Ov025_Hub_InitializeWidgets(self);
    Ov025_PushCountersToEventFlags();
    Ov025_ModelActor_Init(self + 0x98, cfg);
    return 1;
}
