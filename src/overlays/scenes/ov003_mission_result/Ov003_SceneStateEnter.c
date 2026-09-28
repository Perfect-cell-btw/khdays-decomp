typedef struct Ov003RootContextView {
    unsigned char pad0000[0x1290];
    int secondaryPresent[4];
    unsigned char pad12a0[0x4b0];
    int layerValue[4];
    unsigned char pad1760[0x1c];
    int layerTicks[4];
    int primaryActive[4];
    int secondaryActive[4];
} Ov003RootContextView;

extern int NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Scene_DrawNode(void *p);
extern void Ov003_AccumulateThreeGlobalStats(int i, int v);
extern void PlaySoundChecked(int a, int b);
extern unsigned int BuildSlotMask(int p, int a);
extern void Sequence_UpdateTracks(void *p, int a);
extern void SetSelectionIfChanged(int a);
extern int Ov003_StateRebindAnims(void);

int Ov003_SceneStateEnter(void) {
    unsigned short *root;
    unsigned int uVar3;
    int iVar4;
    int iVar11;
    int iVar12;
    int iVar10;

    root = (unsigned short *)NNSi_FndGetCurrentRootHeap();
    iVar10 = 0;
    if (*(int *)(root + 0xf08) == 0) {
        *(int *)(root + 0xf0a) = Ov105_WM_GetLinkLevel();
    }
    Scene_DrawNode(root + 0x84);
    uVar3 = *root;
    iVar11 = 0;
    if (0 < (int)uVar3) {
        unsigned short *puVar5 = root + 0x108;
        unsigned short *puVar6 = root + 0x318;
        unsigned short *puVar7 = root + 0x950;
        unsigned short *puVar8 = root + 0x528;
        unsigned short *puVar9 = root + 0x738;

        do {
            Ov003_AccumulateThreeGlobalStats(iVar11, ((Ov003RootContextView *)root)->layerValue[iVar11]);
            Scene_DrawNode(puVar5);
            Scene_DrawNode(puVar6);
            if (((Ov003RootContextView *)root)->primaryActive[iVar11] != 0) {
                Scene_DrawNode(puVar7);
            }
            if (((Ov003RootContextView *)root)->secondaryActive[iVar11] != 0 &&
                (Scene_DrawNode(puVar8),
                 ((Ov003RootContextView *)root)->secondaryPresent[iVar11] != 0)) {
                Scene_DrawNode(puVar9);
            }
            uVar3 = *root;
            iVar11 = iVar11 + 1;
            puVar5 = puVar5 + 0x84;
            puVar6 = puVar6 + 0x84;
            puVar7 = puVar7 + 0x84;
            puVar8 = puVar8 + 0x84;
            puVar9 = puVar9 + 0x84;
        } while (iVar11 < (int)uVar3);
    }
    if (*(int *)(root + 0x2a) == 1) {
        iVar12 = 0;
        if (0 < (int)uVar3) {
            unsigned short *puVar5 = root + 0x950;
            unsigned short *puVar6 = root + 0x528;
            unsigned short *puVar7 = root + 0x738;

            do {
                if (((Ov003RootContextView *)root)->layerTicks[iVar12] == 0) {
                    ((Ov003RootContextView *)root)->primaryActive[iVar12] = 1;
                    PlaySoundChecked(0x182, 0);
                } else if (((Ov003RootContextView *)root)->primaryActive[iVar12] != 0) {
                    uVar3 = BuildSlotMask((int)puVar5, 0x1000);
                    if ((uVar3 & 1) != 0) {
                        ((Ov003RootContextView *)root)->primaryActive[iVar12] = 0;
                    } else {
                        Sequence_UpdateTracks(puVar5, 0x1000);
                    }
                }
                if (((Ov003RootContextView *)root)->layerTicks[iVar12] == 0x28) {
                    ((Ov003RootContextView *)root)->secondaryActive[iVar12] = 1;
                } else if (((Ov003RootContextView *)root)->secondaryActive[iVar12] != 0 &&
                           (Sequence_UpdateTracks(puVar6, 0x1000),
                            ((Ov003RootContextView *)root)->secondaryPresent[iVar12] != 0)) {
                    Sequence_UpdateTracks(puVar7, 0x1000);
                }
                ((Ov003RootContextView *)root)->layerTicks[iVar12] =
                    ((Ov003RootContextView *)root)->layerTicks[iVar12] + 1;
                puVar5 = puVar5 + 0x84;
                puVar6 = puVar6 + 0x84;
                puVar7 = puVar7 + 0x84;
                iVar12 = iVar12 + 1;
                uVar3 = *root;
            } while (iVar12 < (int)uVar3);
        }
        iVar10 = (int)Ov003_StateRebindAnims;
        iVar4 = 0;
        if (0 < (int)uVar3) {
            do {
                if (((Ov003RootContextView *)root)->primaryActive[iVar4] != 0) {
                    iVar10 = 0;
                    break;
                }
                iVar4 = iVar4 + 1;
            } while (iVar4 < (int)uVar3);
        }
    }
    if (iVar10 != 0) {
        SetSelectionIfChanged(4);
    }
    return iVar10;
}
