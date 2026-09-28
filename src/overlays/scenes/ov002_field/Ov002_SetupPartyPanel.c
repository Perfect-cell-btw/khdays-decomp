typedef struct { int w[10]; } PanelCfg;

extern char *NNSi_FndGetCurrentRootHeap(void);
extern void MI_CpuFill8(void *dst, int value, unsigned size);
extern int func_02023bf0(void);
extern int Archive_LoadFile(void *name, int slot);
extern void NNS_G2dGetUnpackedPaletteData(int handle, char *p);
extern int Ov002_Hud_GetBlock30(void);
extern void TileSurface_Init8bpp(char *p, PanelCfg *cfg);
extern void Ov002_InitResourceRecord(char *p, void *tbl);
extern int Msg_OpenContainerAndReadHeader(void *name, int slot);
extern void Ov002_PanelIdleState(void);
extern PanelCfg data_ov002_0207de90;
extern char *data_ov002_0207f624;
extern int data_ov002_0207eb70;
extern int data_ov002_0207eb8c;
extern int data_ov002_0207eba0;

/* Sets the party panel up from the template config: clears the 0x7e8-byte block, opens the
 * roster (or marks it preloaded), builds the row renderer and loads the icon set. */
void *Ov002_SetupPartyPanel(int preloaded) {
    PanelCfg cfg = data_ov002_0207de90;
    char *self = NNSi_FndGetCurrentRootHeap();
    data_ov002_0207f624 = self;
    MI_CpuFill8(self, 0, 0x7e8);
    *(int *)(self + 0x6a4) = func_02023bf0();
    if (preloaded == 0) {
        *(int *)(self + 4) = Archive_LoadFile(&data_ov002_0207eb70, 0xe);
        NNS_G2dGetUnpackedPaletteData(*(int *)(self + 4), self + 8);
    } else {
        *(int *)(self + 0x664) = 1;
        cfg.w[8] = Ov002_Hud_GetBlock30();
        TileSurface_Init8bpp(self + (0x77 << 4), &cfg);
        Ov002_InitResourceRecord(self + 0x7ac, &data_ov002_0207eb8c);
    }
    *(int *)(self + 0x7e4) = Msg_OpenContainerAndReadHeader(&data_ov002_0207eba0, 0xe);
    return (void *)&Ov002_PanelIdleState;
}
