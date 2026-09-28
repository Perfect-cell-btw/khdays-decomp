typedef unsigned char u8;
typedef signed char s8;
typedef unsigned short u16;
typedef signed short s16;

typedef struct Ov002NodePair {
    u16 a;
    u16 b;
} Ov002NodePair;

typedef int (*Ov002NodeSampleFn)(int nValue, int nArg, int bReady);

typedef struct Ov002TaskNode {
    void *pHook0;
    void *pHook1;
    void *pHook2;
    int nThreshold;
    s8 nResult;             /* -2 not satisfied, -1 satisfied */
    s8 nLap;
    char pad012[2];
    s16 nKind;
    s16 nResolved;
    s16 nCount;
    char pad01a[2];
    Ov002NodePair *pPairs;
    s16 nArg;
    char pad022[2];
    Ov002NodeSampleFn pfnSample;
    u8 bMode;
} Ov002TaskNode;

extern int GameState_GetField(int a, int b);         /* read one progress pair */
extern int Ov002_SetLapRunning(int bStart, int nLap);
extern void Ov002_NodeFinishLap(void);
extern void Ov002_ReleaseNodePairs(void);
extern void Ov002_NodeHandlePhase(void);
extern void Ov002_NodeGetResult(void);

/* Writes a hook slot only when the caller hands over something other than -1,
   which is how a caller says "leave this one alone". */
static inline void Ov002_SetHooks(Ov002TaskNode *pNode, void *pA, void *pB,
                                  void *pC)
{
    if (pA != (void *)-1) {
        pNode->pHook0 = pA;
    }
    if (pB != (void *)-1) {
        pNode->pHook1 = pB;
    }
    if (pC != (void *)-1) {
        pNode->pHook2 = pC;
    }
}

/* Walks the node's pairs, feeding each reading to the node's own sampler, and
   leaves the verdict in nResult.  If the node ended up satisfied it then hands
   itself to the next pair of hooks: with a positive threshold it starts a lap
   first and reports -2 so the caller keeps waiting, otherwise it settles for
   good and reports the verdict. */
int Ov002_NodeEvaluate(Ov002TaskNode *pNode)
{
    int i;
    int nValue;

    pNode->nResult = (s8)((pNode->bMode == 0) ? -2 : -1);

    if (pNode->nKind != -1 && pNode->nResolved < 0) {
        return -2;
    }

    for (i = 0; i < pNode->nCount; i++) {
        nValue = (s16)GameState_GetField(pNode->pPairs[i].a, pNode->pPairs[i].b);
        pNode->nResult = (s8)(pNode->pfnSample(nValue, pNode->nArg,
                                               (pNode->nResult != -2) ? 1 : 0)
                              ? -1 : -2);
    }

    if (pNode->nResult != -2) {
        if (pNode->nThreshold > 0) {
            pNode->nLap = (s8)Ov002_SetLapRunning(1, -1);
            if (pNode->nLap < 0) {
                return -2;
            }
            Ov002_SetHooks(pNode, (void *)Ov002_NodeFinishLap,
                           (void *)Ov002_ReleaseNodePairs,
                           (void *)Ov002_NodeHandlePhase);
            return -2;
        }
        Ov002_SetHooks(pNode, (void *)Ov002_NodeGetResult,
                       (void *)Ov002_ReleaseNodePairs,
                       (void *)Ov002_NodeHandlePhase);
    }
    return pNode->nResult;
}
