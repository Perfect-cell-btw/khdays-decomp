/* Mission result fade state: fills the remaining rank rows and slides the table out. */

typedef struct Ov003RootTail {
    unsigned char pad0000[0x1774];
    int nStateTicks;
} Ov003RootTail;

extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Ov003_UpdateLayers(void *p);
extern void Ov003_FillHudTileGrid(int i, int v);
extern void GFXi_EnqueueCommand(int a, int b, void *p, int n);
extern void Ov003_AdvanceAnims(void *p);
extern int Ov003_StateUpdate(void);

int Ov003_SceneStateFadeOut(void)
{
    unsigned short *root;
    unsigned int uVar3;
    int iVar4;
    int iVar5;
    int d;

    root = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    iVar4 = 0;
    if (*(int *)(root + 0xf08) == 0) {
        *(int *)(root + 0xf0a) = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers(root);
    if (*(int *)(root + 0xbba) == 0) {
        uVar3 = *root;
        iVar5 = 0;
        if (0 < (int)uVar3) {
            do {
                if (((int *)root)[iVar5 + 0xb] < (int)(uVar3 - 1)) {
                    Ov003_FillHudTileGrid(iVar5, ((int *)root)[iVar5 + 0xb]);
                }
                uVar3 = *root;
                iVar5 = iVar5 + 1;
            } while (iVar5 < (int)uVar3);
        }
        GFXi_EnqueueCommand(9, 0, root + 0xbdc, 0x600);
        GFXi_EnqueueCommand(0x19, 0, root + 0xbdc, 0x600);
        *(int *)(root + 0xf06) = 0x10;
    } else {
        GFXi_EnqueueCommand(0x19, 0, root + 0xbdc, 0x600);
        d = 0x10 - *(int *)(root + 0xbba);
        *(int *)(root + 0xf06) = d;
        if (d <= 0) {
            *(int *)(root + 0xf06) = 0;
            iVar4 = (int)Ov003_StateUpdate;
        }
    }
    Ov003_AdvanceAnims(root);
    if (iVar4 == 0) {
        ((Ov003RootTail *)root)->nStateTicks =
            ((Ov003RootTail *)root)->nStateTicks + 1;
    } else {
        ((Ov003RootTail *)root)->nStateTicks = 0;
    }
    return iVar4;
}
