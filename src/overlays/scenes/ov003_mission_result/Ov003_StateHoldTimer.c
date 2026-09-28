/* Holds for 30 frames, then binds each character's pose for its rank group and moves on once every
 * character is ready. */

#include "nitro/types.h"

typedef struct {
    u8 raw[0x108];
} Ov003AnimObject;

typedef struct {
    u8 raw[0x24];
} Ov003AnimBinding;

typedef struct {
    u16 nPlayerCount;                       /* +0x0000 */
    u8 pad0002[0x2a];
    int aRankGroups[4];                     /* +0x002c */
    u8 pad003c[0x18];
    int nLayerMode;                         /* +0x0054 */
    u8 pad0058[0x9f8];
    Ov003AnimObject aMainAnims[4];          /* +0x0a50, stride 0x108 */
    Ov003AnimObject aExtraAnims[4];         /* +0x0e70, stride 0x108 */
    int aHasExtraAnim[4];                   /* +0x1290 */
    u8 pad12a0[0x420];
    Ov003AnimBinding aAnimBindings[4];      /* +0x16c0, stride 0x24 */
    int aAnimTimers[4];                     /* +0x1750 */
    u8 pad1760[4];
    int aAnimFinished[4];                   /* +0x1764 */
    int nHoldTimer;                         /* +0x1774 */
    int nTransitionLatch;                   /* +0x1778 */
    u8 pad177c[0x694];
    int nVariantMode;                       /* +0x1e10 */
    int nVariantValue;                      /* +0x1e14 */
} Ov003SceneContext;

extern Ov003SceneContext *NNSi_FndGetCurrentRootHeap(void);
extern int Ov105_WM_GetLinkLevel(void);
extern void Ov003_UpdateLayers(Ov003SceneContext *pContext);
extern void BindAnimTrack(int nObject, int nTrack, int nBinding, int nAnim);
extern unsigned int BuildSlotMask(int nObject, int nMask);
extern void Sequence_UpdateTracks(void *pObject, int nMask);
extern int Ov003_StateCountdownValues(void);
extern int Ov003_SceneStateActive(void);

int Ov003_StateHoldTimer(void)
{
    int nNextState;
    Ov003SceneContext *root;
    unsigned int nMask;
    int bAllEligible;
    Ov003AnimBinding *pBinding;
    Ov003AnimObject *pMainAnim;
    Ov003AnimObject *pExtraAnim;
    int i;

    root = NNSi_FndGetCurrentRootHeap();
    nNextState = 0;
    if (root->nVariantMode == 0) {
        root->nVariantValue = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers(root);

    if (root->nLayerMode == 1) {
        i = root->nHoldTimer;
        root->nHoldTimer = i + 1;
        if (i + 1 >= 30) {
            bAllEligible = 1;
            i = 0;
            if (0 < (int)(unsigned int)root->nPlayerCount) {
                pBinding = &root->aAnimBindings[0];
                pMainAnim = &root->aMainAnims[0];
                pExtraAnim = &root->aExtraAnims[0];
                do {
                    if (root->aRankGroups[i] == 0) {
                        BindAnimTrack((int)pMainAnim, 0, (int)pBinding, 1);
                        if (root->aHasExtraAnim[i] != 0) {
                            BindAnimTrack((int)pExtraAnim, 0,
                                          (int)((u8 *)pExtraAnim + 0xe0), 1);
                        }
                        nNextState = (int)Ov003_StateCountdownValues;
                        root->nHoldTimer = 0;
                    }
                    if (root->aRankGroups[i] == 3) {
                        bAllEligible = 0;
                    }
                    i++;
                    pBinding++;
                    pMainAnim++;
                    pExtraAnim++;
                } while (i < (int)(unsigned int)root->nPlayerCount);
            }
            if (bAllEligible) {
                root->nHoldTimer = 0;
                nNextState = (int)Ov003_SceneStateActive;
                root->nTransitionLatch = 0;
            }
        }

        {
            Ov003AnimObject *pMainAnim2;
            Ov003AnimBinding *pBinding2;
            Ov003AnimObject *pExtraAnim2;
            int j;

            j = 0;
            if (0 < (int)(unsigned int)root->nPlayerCount) {
                pMainAnim2 = &root->aMainAnims[0];
                pBinding2 = &root->aAnimBindings[0];
                pExtraAnim2 = &root->aExtraAnims[0];
                do {
                    if (root->aRankGroups[j] != 0 && root->aRankGroups[j] != 3 &&
                        (nMask = BuildSlotMask((int)pMainAnim2, 0x1000), (nMask & 1) != 0) &&
                        (BindAnimTrack((int)pMainAnim2, 0, (int)pBinding2, 5),
                         root->aHasExtraAnim[j] != 0)) {
                        BindAnimTrack((int)pExtraAnim2, 0,
                                      (int)((u8 *)pExtraAnim2 + 0xe0), 5);
                    }
                    Sequence_UpdateTracks(pMainAnim2, 0x1000);
                    if (root->aHasExtraAnim[j] != 0) {
                        Sequence_UpdateTracks(pExtraAnim2, 0x1000);
                    }
                    pMainAnim2++;
                    pBinding2++;
                    pExtraAnim2++;
                    j++;
                } while (j < (int)(unsigned int)root->nPlayerCount);
            }
        }
    }
    return nNextState;
}

