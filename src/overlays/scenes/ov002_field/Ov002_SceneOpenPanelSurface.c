/*
 * Ov002_SceneOpenPanelSurface - hand the panel's tile block to the hardware and
 * bring the surface it draws into up, once.
 *
 * The node's resource is looked up, its character block queued to VRAM and its
 * palette queued behind it, and the node itself released - none of which depends
 * on the surface existing yet. The surface is only built the first time: the two
 * scratch buffers are claimed, the four words the scene set aside describe it,
 * and the optional source at +0x68c+4 is passed only when the word at +0x68c
 * says there is one. The scene then moves to state 2 and arms its next step.
 *
 * THUMB.
 */

#include "nitro/types.h"

typedef struct {
    int aRect[4];                       /* +0x668 */
    u8 pad0678[0x14];
    int nHasSource;                     /* +0x68c */
    int aSource[1];                     /* +0x690 */
} Ov002SurfaceParams;

typedef struct {
    int nState;                         /* +0x000 */
    u8 pad0004[4];
    int *pTileSet;                      /* +0x008 */
    u8 pad000c[4];
} Ov002SceneContext;

extern Ov002SceneContext *data_ov002_0207f624;

extern void GetResourceSubBlock_CHAR(unsigned int nResource, int *pBlock);
extern void GFXi_EnqueueCommand(int nKind, int nSize, int nSource, int nDest);
extern void Obj_SetField14(int nObject, void *pStep);

extern unsigned int Ov002_GetWord8(void *pNode);
extern void Ov002_DestroyOwnedEntry(void *pNode, int nValue);
extern void Ov002_InitSurfaceContext(void *pSurface, int nKind, int nSize, int a0,
                                int a1, int a2, int a3, int nBufferA,
                                int nBufferB, void *pSource, int nLast);
extern void Ov002_SelectEntryByKey(int nKey);
extern int Ov002_GetItemResource(int nId);
extern void Ov002_EnqueueAndRecordCommand(int nKind, int nSize, int nSource, int nDest,
                                unsigned int nResource);
extern void Ov002_SceneOpenPanelStep(void);

void Ov002_SceneOpenPanelSurface(void *pNode)
{
    Ov002SceneContext *ctx;
    Ov002SurfaceParams *p;
    void *pSource;
    unsigned int nResource;
    int nBlock;
    int nBufferA;
    int nBufferB;

    ctx = data_ov002_0207f624;
    p = (Ov002SurfaceParams *)((char *)ctx + 0x668);
    nResource = Ov002_GetWord8(pNode);
    GetResourceSubBlock_CHAR(nResource, &nBlock);
    Ov002_EnqueueAndRecordCommand(7, 0x4c00, *(int *)(nBlock + 0x14),
                        *(int *)(nBlock + 0x10), nResource);
    GFXi_EnqueueCommand(0xf, 0x180, ctx->pTileSet[3], 0x20);
    Ov002_DestroyOwnedEntry(pNode, 0);

    if (*(int *)((char *)ctx + 0x660) == 0) {
        Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x69c));
        if (p->nHasSource == 0) {
            pSource = 0;
        } else {
            pSource = p->aSource;
        }
        nBufferA = Ov002_GetItemResource(0xb);
        nBufferB = Ov002_GetItemResource(10);
        Ov002_InitSurfaceContext((char *)ctx + 0xc, 3, 0x260, p->aRect[0], p->aRect[1],
                            p->aRect[2], p->aRect[3], nBufferA, nBufferB, pSource,
                            0xc);
        Ov002_SelectEntryByKey(*(int *)((char *)ctx + 0x6a0));
        *(int *)((char *)ctx + 0x660) = 1;
    }

    ctx->nState = 2;
    Obj_SetField14(*(int *)((char *)ctx + 0x6a4), Ov002_SceneOpenPanelStep);
}
