extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Ov003_UpdateLayers(void *p);
extern void Ov003_AdvanceAnims(void *p);
extern int Ov003_SceneStateActive(void);

int Ov003_StatePrepare(void) {
    unsigned short *root;
    int iVar3;
    int iVar4;

    root = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    iVar4 = 0;
    if (*(int *)(root + 0xf08) == 0) {
        *(int *)(root + 0xf0a) = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers(root);
    if (*(int *)(root + 0xbba) == 0) {
        *(int *)(root + 0xbd8) = 0;
        *(int *)(root + 0xbda) = 0x1f;
    } else {
        iVar3 = *(int *)(root + 0xbd8);
        *(int *)(root + 0xbd8) = iVar3 - 6;
        if (iVar3 - 6 < -0xbf) {
            *(int *)(root + 0xbd6) = 1;
            *(int *)(root + 0xbd8) = -0xbf;
            *(int *)(root + 0xbba) = 0;
            iVar4 = (int)Ov003_SceneStateActive;
            *(int *)(root + 0xbbc) = 1;
        }
        iVar3 = *(int *)(root + 0xbda);
        *(int *)(root + 0xbda) = iVar3 - 1;
        if (iVar3 - 1 < 0) {
            *(int *)(root + 0xbda) = 0;
        }
    }
    Ov003_AdvanceAnims(root);
    if (iVar4 == 0) {
        *(int *)(root + 0xbba) = *(int *)(root + 0xbba) + 1;
    }
    return iVar4;
}
