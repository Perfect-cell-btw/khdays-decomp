extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Ov003_UpdateLayers(void *p);
extern int G2_GetBG3ScrPtr(void);
extern int G2S_GetBG0ScrPtr(void);
extern void func_02013484(int a, void *b, int c, int d, int e, int f, int g, int h, int i, int j);
extern void Ov003_AdvanceAnims(void *p);
extern int Ov003_IsGlobalBit0Set(void);
extern void PlaySoundChecked(int a, int b);
extern int Ov003_StatePrepare(void);
extern int Ov003_SceneStateFadeIn(void);

int Ov003_StateUpdate(void) {
    unsigned short *root;
    int iVar4;

    root = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    if (*(int *)(root + 0xf08) == 0) {
        *(int *)(root + 0xf0a) = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers(root);
    iVar4 = *(int *)(root + 0xbba);
    *(int *)(root + 0xbba) = iVar4 + 1;
    if (iVar4 + 1 == 2) {
        func_02013484(G2_GetBG3ScrPtr(), *(unsigned short **)(root + 0xef2), 0, 0, 8, 0x16, 0x20, 0x18, 0x10, 2);
        func_02013484(G2S_GetBG0ScrPtr(), *(unsigned short **)(root + 0xef2), 0, 0, 8, 0x16, 0x20, 0x18, 0x10, 2);
    }
    if (*(int *)(root + 0xbba) >= 0x40) {
        *(int *)(root + 0xbba) = 0;
    }
    iVar4 = *(int *)(root + 0xbba);
    if (iVar4 < 0x10) {
        *(int *)(root + 0xf04) = iVar4;
    } else if (iVar4 < 0x30) {
        *(int *)(root + 0xf04) = 0xf;
    } else {
        *(int *)(root + 0xf04) = 0x3f - iVar4;
    }
    Ov003_AdvanceAnims(root);
    if (Ov003_IsGlobalBit0Set() == 0) {
        return 0;
    }
    PlaySoundChecked(0, 1);
    *(int *)(root + 0xbba) = 0;
    *(int *)(root + 0xf04) = 0;
    return (*(int *)(root + 0xbbc) == 0) ? (int)Ov003_StatePrepare : (int)Ov003_SceneStateFadeIn;
}
