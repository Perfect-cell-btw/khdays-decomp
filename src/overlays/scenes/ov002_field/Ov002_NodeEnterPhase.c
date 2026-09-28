#include "nitro/types.h"

typedef struct Ov002TaskNode Ov002TaskNode;

typedef int (*Ov002NodeHook)(Ov002TaskNode *pNode);

struct Ov002TaskNode {
    Ov002NodeHook pHook0;
    Ov002NodeHook pHook1;
    Ov002NodeHook pHook2;
    int nThreshold;
    s8 nResult;
    s8 nLap;
    char pad012[2];
    s16 nKind;
};

/* The entry the session currently offers to whichever node asks for it. */
typedef struct Ov002NodeKindEntry {
    s8 nResult;             /* result a node adopts from this entry */
    u8 nKind;               /* kind the entry belongs to */
} Ov002NodeKindEntry;

extern Ov002NodeKindEntry *Ov002_GetOfferedKindEntry(void);
/* Starts (bStart != 0) or stops a lap; returns the lap, negative on failure. */
extern int Ov002_SetLapRunning(int bStart, int nLap);
extern int Ov002_NodeFinishLap(Ov002TaskNode *pNode);
extern int Ov002_NodeGetResult(Ov002TaskNode *pNode);

/* Writes a hook slot unless the caller passes -1, which means "leave this one
   as it is". */
static inline void Ov002_SetHook(Ov002NodeHook *pSlot, Ov002NodeHook pHook)
{
    if ((int)pHook != -1) {
        *pSlot = pHook;
    }
}

/* Node entry phase: the node picks up the entry the session is offering, as
   long as the entry is valid and matches the kind the node was asked for.
   With a payload threshold it takes a lap of its own and waits on the lap
   finisher; without one it goes straight to the follow-up hook. */
int Ov002_NodeEnterPhase(Ov002TaskNode *pNode)
{
    Ov002NodeKindEntry *pEntry;

    pEntry = Ov002_GetOfferedKindEntry();
    pNode->nResult = -2;
    if (pEntry->nResult >= 0) {
        if (pNode->nKind < 0 || pNode->nKind == pEntry->nKind) {
            pNode->nResult = pEntry->nResult;
        }
    }

    if (pNode->nResult != -2) {
        if (pNode->nThreshold > 0) {
            pNode->nLap = (s8)Ov002_SetLapRunning(1, -1);
            if (pNode->nLap < 0) {
                return -2;
            }
            Ov002_SetHook(&pNode->pHook0, Ov002_NodeFinishLap);
            Ov002_SetHook(&pNode->pHook1, 0);
            Ov002_SetHook(&pNode->pHook2, 0);
            return -2;
        }
        Ov002_SetHook(&pNode->pHook0, Ov002_NodeGetResult);
        Ov002_SetHook(&pNode->pHook1, 0);
        Ov002_SetHook(&pNode->pHook2, 0);
    }

    return pNode->nResult;
}
