/* Ov002_CreatePairCompareNode: instantiate a progress-pair comparison node. */
typedef unsigned short u16;
typedef struct Ov002NodePair { u16 a, b; } Ov002NodePair;
typedef int (*Ov002NodeSampleFn)(int nValue, int nArg, int bReady);
typedef struct Ov002TaskNode {
    void *pHook0, *pHook1, *pHook2;
    int nThreshold;
    signed char nResult, nLap;
    char pad012[2];
    short nKind, nResolved, nCount;
    char pad01a[2];
    Ov002NodePair *pPairs;
    short nArg;
    char pad022[2];
    Ov002NodeSampleFn pfnSample;
    unsigned char bMode;
} Ov002TaskNode;
extern void *NNSi_FndAllocFromDefaultExpHeap(unsigned int nSize);
extern int Ov002_EqualOrNonzero(int,int,int);
extern int Ov002_CompareEqualAndReady(int,int,int);
extern int Ov002_GreaterOrNonzero(int,int,int);
extern int Ov002_CompareGreaterAndReady(int,int,int);
extern int Ov002_LessOrNonzero(int,int,int);
extern int Ov002_CompareLessAndReady(int,int,int);
extern int Ov002_GreaterEqualOrNonzero(int,int,int);
extern int Ov002_CompareGreaterEqualAndReady(int,int,int);
extern int Ov002_LessEqualOrNonzero(int,int,int);
extern int Ov002_CompareLessEqualAndReady(int,int,int);
extern int Ov002_NotEqualOrNonzero(int,int,int);
extern int Ov002_NotEqualAndNonzero(int,int,int);
extern int Ov002_NodeEvaluate(Ov002TaskNode *);
extern void Ov002_ReleaseNodePairs(Ov002TaskNode *);
extern int Ov002_NodeHandlePhase(Ov002TaskNode *,int);

static inline void Ov002_SetHooks(Ov002TaskNode *pNode, void *pA, void *pB, void *pC)
{
    if (pA != (void *)-1) pNode->pHook0 = pA;
    if (pB != (void *)-1) pNode->pHook1 = pB;
    if (pC != (void *)-1) pNode->pHook2 = pC;
}

Ov002TaskNode *Ov002_CreatePairCompareNode(int nKind, int nMode, int nCount,
    const u16 *pValueKeys, const u16 *pValueWidths, unsigned char nCompareOp,
    short nArg, int nThreshold)
{
    Ov002TaskNode *pNode;
    int i;
    pNode = NNSi_FndAllocFromDefaultExpHeap(0x2c);
    pNode->pPairs = NNSi_FndAllocFromDefaultExpHeap(nCount * 4);
    pNode->nKind = nKind;
    pNode->nResolved = -1;
    pNode->nCount = nCount;
    pNode->nArg = nArg;
    pNode->bMode = nMode;
    pNode->nThreshold = nThreshold;
    switch (nCompareOp) {
    case 0: case 1: case 2: case 3: case 4: case 5: case 6: break;
    case 7: pNode->pfnSample = nMode == 0 ? Ov002_EqualOrNonzero : Ov002_CompareEqualAndReady; break;
    case 8: pNode->pfnSample = nMode == 0 ? Ov002_GreaterOrNonzero : Ov002_CompareGreaterAndReady; break;
    case 9: pNode->pfnSample = nMode == 0 ? Ov002_LessOrNonzero : Ov002_CompareLessAndReady; break;
    case 10: pNode->pfnSample = nMode == 0 ? Ov002_GreaterEqualOrNonzero : Ov002_CompareGreaterEqualAndReady; break;
    case 11: pNode->pfnSample = nMode == 0 ? Ov002_LessEqualOrNonzero : Ov002_CompareLessEqualAndReady; break;
    case 12: pNode->pfnSample = nMode == 0 ? Ov002_NotEqualOrNonzero : Ov002_NotEqualAndNonzero; break;
    }
    for (i = 0; i < nCount; i++) {
        pNode->pPairs[i].a = pValueKeys[i];
        pNode->pPairs[i].b = pValueWidths[i];
    }
    Ov002_SetHooks(pNode, (void *)Ov002_NodeEvaluate,
        (void *)Ov002_ReleaseNodePairs, (void *)Ov002_NodeHandlePhase);
    return pNode;
}
