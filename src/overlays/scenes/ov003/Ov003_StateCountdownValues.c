/* Counts the result characters' rank timers down and binds each top-ranked character's victory pose
 * on the beat; moves to the display state when done. */

#include "nitro/types.h"
#include "game/engine.h"

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
    int nPhaseAccumulator;                  /* +0x1760 */
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
extern void Sequence_UpdateTracks(void *pObject, int nMask);
extern int Ov003_SceneStateActive(void);

int Ov003_StateCountdownValues(void)
{
    Ov003SceneContext *root;
    unsigned int nMask;
    int nNextState;
    int i;
    Ov003AnimBinding *pBinding;
    Ov003AnimObject *pMainAnim;
    Ov003AnimObject *pExtraAnim;

    root = NNSi_FndGetCurrentRootHeap();
    nNextState = 0;
    if (root->nVariantMode == 0) {
        root->nVariantValue = Ov105_WM_GetLinkLevel();
    }
    Ov003_UpdateLayers(root);

    if (root->nLayerMode == 1) {
        i = 0;
        root->nPhaseAccumulator = (root->nPhaseAccumulator + 0x2000) & 0xffff;
        if (0 < (int)(unsigned int)root->nPlayerCount) {
            pBinding = &root->aAnimBindings[0];
            pMainAnim = &root->aMainAnims[0];
            pExtraAnim = &root->aExtraAnims[0];
            do {
                if (root->aRankGroups[i] == 3) {
                    if (root->aAnimTimers[i] > 0x6400) {
                        root->aAnimTimers[i] -= 400;
                    } else if (root->nPhaseAccumulator == 0) {
                        BindAnimTrack((int)pMainAnim, 0, (int)pBinding, 4);
                        if (root->aHasExtraAnim[i] != 0) {
                            BindAnimTrack((int)pExtraAnim, 0,
                                          (int)((u8 *)pExtraAnim + 0xe0), 4);
                        }
                        root->nHoldTimer = 0;
                        nNextState = (int)Ov003_SceneStateActive;
                        root->nTransitionLatch = 0;
                    }
                }

                if (root->aRankGroups[i] != 3 &&
                    (nMask = BuildSlotMask((int)pMainAnim, 0x1000), (nMask & 1) != 0)) {
                    if (root->aRankGroups[i] == 0) {
                        BindAnimTrack((int)pMainAnim, 0, (int)pBinding, 2);
                        if (root->aHasExtraAnim[i] != 0) {
                            BindAnimTrack((int)pExtraAnim, 0,
                                          (int)((u8 *)pExtraAnim + 0xe0), 2);
                        }
                    } else {
                        BindAnimTrack((int)pMainAnim, 0, (int)pBinding, 5);
                        if (root->aHasExtraAnim[i] != 0) {
                            BindAnimTrack((int)pExtraAnim, 0,
                                          (int)((u8 *)pExtraAnim + 0xe0), 5);
                        }
                    }
                }

                Sequence_UpdateTracks(pMainAnim, 0x1000);
                if (root->aHasExtraAnim[i] != 0) {
                    Sequence_UpdateTracks(pExtraAnim, 0x1000);
                }
                pBinding++;
                pMainAnim++;
                pExtraAnim++;
                i++;
            } while (i < (int)(unsigned int)root->nPlayerCount);
        }
    }
    return nNextState;
}
