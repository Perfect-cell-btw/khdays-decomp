#include "nitro/types.h"

typedef struct Ov002TaskNode Ov002TaskNode;

/* Every hook slot holds a per-phase entry point for the node. */
typedef int (*Ov002NodeHook)(Ov002TaskNode *pNode);

struct Ov002TaskNode {
    Ov002NodeHook pHook0;
    Ov002NodeHook pHook1;
    Ov002NodeHook pHook2;
    int nThreshold;         /* payload the lap has to reach to finish */
    s8 nResult;             /* value handed back once the lap is done */
    s8 nLap;                /* lap this node owns, -1 when it holds none */
    char pad012[2];
};

/* Payload accumulated so far by the given lap. */
extern unsigned int Ov002_GetPhaseSlotPayload(int nLap);
/* Starts (bStart != 0) or stops the given lap; negative on failure. */
extern int Ov002_SetLapRunning(int bStart, int nLap);
/* Hook this node runs once its lap has been handed back. */
extern int Ov002_NodeGetResult(Ov002TaskNode *pNode);

/* Writes a hook slot unless the caller passes -1, which means "leave this one
   as it is". */
static inline void Ov002_SetHook(Ov002NodeHook *pSlot, Ov002NodeHook pHook)
{
    if ((int)pHook != -1) {
        *pSlot = pHook;
    }
}

/* Finishes the lap this node owns once the lap has gathered enough payload:
   the lap is stopped and released, and the node moves on to its follow-up
   hook while keeping the other two slots.  Until then, and whenever the lap
   cannot be stopped, the node reports -2 and stays where it is. */
int Ov002_NodeFinishLap(Ov002TaskNode *pNode)
{
    unsigned int nPayload;

    nPayload = Ov002_GetPhaseSlotPayload(pNode->nLap);
    if (nPayload != 0 && nPayload >= (unsigned int)pNode->nThreshold) {
        if (Ov002_SetLapRunning(0, pNode->nLap) < 0) {
            return -2;
        }
        pNode->nLap = -1;
        Ov002_SetHook(&pNode->pHook0, Ov002_NodeGetResult);
        Ov002_SetHook(&pNode->pHook1, (Ov002NodeHook)-1);
        Ov002_SetHook(&pNode->pHook2, (Ov002NodeHook)-1);
        return pNode->nResult;
    }
    return -2;
}
