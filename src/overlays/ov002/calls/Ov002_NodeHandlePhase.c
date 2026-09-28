typedef signed char s8;
typedef signed short s16;

typedef struct Ov002TaskNode {
    void *pHook0;
    void *pHook1;
    void *pHook2;           /* this function's own slot */
    char pad00c[5];
    s8 nLap;                /* lap timer slot, -1 when the node holds none */
    char pad012[2];
    s16 nKind;
    s16 nResolved;
} Ov002TaskNode;

int Ov002_NodeHandlePhase(Ov002TaskNode *pNode, int nPhase);

extern int Ov002_GetCtxTableByte(int nKind);      /* kind -> table byte */
extern int Ov002_SetLapRunning(int bStart, int nLap);
extern void Ov002_NodeEvaluate(void);
extern void Ov002_ReleaseNodePairs(void);

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

/* One node's phase hook.  Phase 0 re-resolves the node's kind; phase 1 stops
   whatever lap it holds and then reinstalls the whole hook triple, this
   function included.  Any other phase does nothing. */
int Ov002_NodeHandlePhase(Ov002TaskNode *pNode, int nPhase)
{
    switch (nPhase) {
    case 0:
        if (pNode->nKind >= 0) {
            pNode->nResolved = (s16)Ov002_GetCtxTableByte(pNode->nKind);
        }
        break;

    case 1:
        if (pNode->nLap != -1) {
            if (Ov002_SetLapRunning(0, pNode->nLap) < 0) {
                return -1;
            }
        }
        Ov002_SetHooks(pNode, (void *)Ov002_NodeEvaluate,
                       (void *)Ov002_ReleaseNodePairs,
                       (void *)Ov002_NodeHandlePhase);
        break;
    }
    return 0;
}
