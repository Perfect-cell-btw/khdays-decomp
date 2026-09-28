typedef struct Ov003RootTail {
    unsigned char pad0000[0x1774];
    int nStateTicks;
} Ov003RootTail;

extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Ov003_UpdateLayers(void *p);
extern void MIi_CpuClear16(int a, void *b, int c);
extern void Ov003_DrawStatGrid(void);
extern void func_02013484(void *a, void *b, int c, int d, int e, int f, int g, int h, int i, int j);
extern void GFXi_EnqueueCommand(int a, int b, void *p, int n);
extern unsigned int BuildSlotMask(int p, int a);
extern void BindAnimTrack(int a, int b, int c, int d);
extern void Sequence_UpdateTracks(void *p, int a);
extern int Ov003_SceneStateFadeOut(void);
extern int Ov003_StateUpdate(void);

int Ov003_SceneStateActive(void) {
    unsigned short *root;
    unsigned int uVar3;
    int iVar4;
    int iVar9;
    int iVar5;

    root = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    iVar9 = 0;
    if (*(int *)(root + 0xf08) == 0) {
        *(int *)(root + 0xf0a) = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers(root);
    if (*(int *)(root + 0xbba) == 0) {
        if (*(int *)(root + 0xbbc) != 0) {
            MIi_CpuClear16(0, root + 0xbdc, 0x600);
            Ov003_DrawStatGrid();
            func_02013484(root + 0xbdc, *(unsigned short **)(root + 0xee6), 0, 0, 3, 5, 0x20, 0x18, 0x1a, 0xe);
            GFXi_EnqueueCommand(9, 0, root + 0xbdc, 0x600);
            GFXi_EnqueueCommand(0x19, 0, root + 0xbdc, 0x600);
        }
        *(int *)(root + 0xbd6) = 1;
        *(int *)(root + 0xbd8) = -0xbf;
        *(int *)(root + 0xbda) = 0;
    } else {
        GFXi_EnqueueCommand(0x19, 0, root + 0xbdc, 0x600);
        iVar5 = *(int *)(root + 0xbd8);
        *(int *)(root + 0xbd8) = iVar5 + 6;
        if (0 < iVar5 + 6) {
            *(int *)(root + 0xbd8) = 0;
            *(int *)(root + 0xbba) = 0;
            iVar9 = (*(int *)(root + 0xbbc) == 0) ?
                (int)Ov003_SceneStateFadeOut : (int)Ov003_StateUpdate;
        }
        iVar5 = *(int *)(root + 0xbda);
        iVar4 = iVar5 + 1;
        *(int *)(root + 0xbda) = iVar4;
        if (0x1f < iVar4) {
            *(int *)(root + 0xbda) = 0x1f;
        }
    }
    if (*(int *)(root + 0x2a) == 1) {
        int iVar10;

        uVar3 = *root;
        iVar10 = 0;
        if (0 < (int)uVar3) {
            unsigned short *puVar6 = root + 0x528;
            unsigned short *puVar7 = root + 0xb60;
            unsigned short *puVar8 = root + 0x738;

            do {
                uVar3 = BuildSlotMask((int)puVar6, 0x1000);
                if ((uVar3 & 1) != 0) {
                    if (((int *)root)[iVar10 + 0xb] == 0) {
                        BindAnimTrack((int)puVar6, 0, (int)puVar7, 2);
                        if (((int *)root)[iVar10 + 0x4a4] != 0) {
                            BindAnimTrack((int)puVar8, 0, (int)(puVar8 + 0x70), 2);
                        }
                    } else {
                        BindAnimTrack((int)puVar6, 0, (int)puVar7, 5);
                        if (((int *)root)[iVar10 + 0x4a4] != 0) {
                            BindAnimTrack((int)puVar8, 0, (int)(puVar8 + 0x70), 5);
                        }
                    }
                }
                Sequence_UpdateTracks(puVar6, 0x1000);
                if (((int *)root)[iVar10 + 0x4a4] != 0) {
                    Sequence_UpdateTracks(puVar8, 0x1000);
                }
                puVar6 = puVar6 + 0x84;
                puVar7 = puVar7 + 0x12;
                puVar8 = puVar8 + 0x84;
                iVar10 = iVar10 + 1;
            } while (iVar10 < (int)(unsigned int)*root);
        }
    }
    if (iVar9 == 0) {
        ((Ov003RootTail *)root)->nStateTicks =
            ((Ov003RootTail *)root)->nStateTicks + 1;
    } else {
        ((Ov003RootTail *)root)->nStateTicks = 0;
    }
    return iVar9;
}
