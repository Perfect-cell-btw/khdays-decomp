/* Ov016_CreateBreakableClass -- Ov016_CreateBreakableClass: allocate the class-0x17 definition
 * (ov002 object class 0x90, 0x2e4 bytes), copy the descriptor's model name into +0x58 and its
 * sequence name into +0x68 (empty when the descriptor's is empty), carry the drop slot / id
 * (+0x78 / +0x7a, shorts), the parameter word (+0x7c) and the four placement parameters
 * (+0x80..+0x8c) across, install the ten handlers of the breakable (the object that spawns
 * its drop and plays its sequence when hit) and stamp kind 0x17. */
#include "nitro/types.h"

typedef struct Ov016BreakableDesc {
    char *pszModel;           /* 0x00 */
    char *pszSequence;        /* 0x04 */
    short nDropSlot;          /* 0x08 */
    short nDropId;            /* 0x0a */
    int nParam;               /* 0x0c */
    int nPlaceA;              /* 0x10 */
    int nPlaceB;              /* 0x14 */
    int nPlaceC;              /* 0x18 */
    int nPlaceD;              /* 0x1c */
} Ov016BreakableDesc;

typedef struct Ov016BreakableDef {
    int nField00;             /* 0x00 */
    int nField04;             /* 0x04 */
    void *pfnInit;            /* 0x08 */
    void *pfnRefresh;         /* 0x0c */
    void *pfnSubmit;          /* 0x10 */
    void *pfnRelease;         /* 0x14 */
    void *pfnStart;           /* 0x18 */
    void *pfnHit;             /* 0x1c */
    int nField20;             /* 0x20 */
    void *pfnGetNode;         /* 0x24 */
    void *pfnGetOwner;        /* 0x28 */
    void *pfnGetA;            /* 0x2c */
    void *pad30;
    void *pad34;
    int nField38;             /* 0x38 */
    void *pfnGetB;            /* 0x3c */
    void *pad40;
    int nField44;             /* 0x44 */
    int nField48;
    u16 nKind;                /* 0x4c */
    char pad4e[0xa];
    char szModel[0x10];       /* 0x58 */
    char szSequence[0x10];    /* 0x68 */
    short nDropSlot;          /* 0x78 */
    short nDropId;            /* 0x7a */
    int nParam;               /* 0x7c */
    int nPlaceA;              /* 0x80 */
    int nPlaceB;              /* 0x84 */
    int nPlaceC;              /* 0x88 */
    int nPlaceD;              /* 0x8c */
} Ov016BreakableDef;

extern void *Ov002_CreateEntryPool(int nClass, int nSize, int nOwner);
extern char *strncpy(char *pDst, const char *pSrc, unsigned int nLen);
extern int   strlen(const char *pStr);
extern void Ov016_SetByteAt0x2bcTo1(void);
extern void Ov016_ReleaseEmbeddedNode_2(void);
extern void Ov016_SubmitRenderNode(void);
extern void Ov016_BreakableRelease(void);
extern void Ov016_BreakableStart(void);
extern void Ov016_BreakableHit(void);
extern void Ov016_AddrOf0x1cIfByte0x2bcClear(void);
extern void Ov016_GetWordVia8Then0x80(void);
extern void Ov016_AddrOfField0xE0_2(void);
extern void Ov016_SetEmbeddedSceneNodeEnabled_2(void);

Ov016BreakableDef *Ov016_CreateBreakableClass(int nOwner, Ov016BreakableDesc *pDesc)
{
    Ov016BreakableDef *pDef;
    char *pszSequence;

    pDef = Ov002_CreateEntryPool(0x90, 0xb9 * 4, nOwner);
    strncpy(pDef->szModel, pDesc->pszModel, 0x10);
    pszSequence = pDesc->pszSequence;
    if (strlen(pszSequence) != 0) {
        strncpy(pDef->szSequence, pszSequence, 0x10);
    } else {
        pDef->szSequence[0] = 0;
    }
    pDef->nDropSlot = pDesc->nDropSlot;
    pDef->nDropId = pDesc->nDropId;
    pDef->nParam = pDesc->nParam;
    pDef->nPlaceA = pDesc->nPlaceA;
    pDef->nPlaceB = pDesc->nPlaceB;
    pDef->nPlaceC = pDesc->nPlaceC;
    pDef->nPlaceD = pDesc->nPlaceD;
    pDef->nField00 = 0;
    pDef->nField04 = 0;
    pDef->pfnInit = (void *)Ov016_SetByteAt0x2bcTo1;
    pDef->pfnRefresh = (void *)Ov016_ReleaseEmbeddedNode_2;
    pDef->pfnSubmit = (void *)Ov016_SubmitRenderNode;
    pDef->pfnRelease = (void *)Ov016_BreakableRelease;
    pDef->pfnStart = (void *)Ov016_BreakableStart;
    pDef->pfnHit = (void *)Ov016_BreakableHit;
    pDef->nField20 = 0;
    pDef->pfnGetNode = (void *)Ov016_AddrOf0x1cIfByte0x2bcClear;
    pDef->pfnGetOwner = (void *)Ov016_GetWordVia8Then0x80;
    pDef->pfnGetA = (void *)Ov016_AddrOfField0xE0_2;
    pDef->nField38 = 0;
    pDef->nField44 = 0;
    pDef->pfnGetB = (void *)Ov016_SetEmbeddedSceneNodeEnabled_2;
    pDef->nKind = 0x17;
    return pDef;
}
