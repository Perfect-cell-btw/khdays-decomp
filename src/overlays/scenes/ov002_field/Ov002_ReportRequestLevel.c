#include "nitro/types.h"

typedef struct Ov002RequestBlock {
    int nPauseObject;       /* -1 while there is nothing to report */
    char pad004[4];
    s8 nRequestLevel;
    char pad009[0x6e];
    u8 bRequestReady;       /* has to be exactly 1 */
} Ov002RequestBlock;

extern char *data_ov002_0207fa00;

extern int QueryActiveStateOrDelegate(void);         /* the local peer */
extern void Ov002_SetCursorRequest(u16 a, u16 b, u16 c, int nLevel);

/* Forwards the pending request's level.  Does nothing unless the request is
   live and ready.  When the local peer's bit is raised in the ready mask the
   caller's flags gain bit 8 first, and the level is floored at -1. */
void Ov002_ReportRequestLevel(int nFlags, int a1, int a2)
{
    char *pRoot;
    Ov002RequestBlock *pRequest;
    int nLevel;

    pRoot = data_ov002_0207fa00;
    pRequest = (Ov002RequestBlock *)(pRoot + 0x8c94);
    if (pRequest->nPauseObject == -1) {
        return;
    }
    if (pRequest->bRequestReady != 1) {
        return;
    }

    if ((*(u8 *)(pRoot + 0x8c8b) & (1 << QueryActiveStateOrDelegate())) != 0) {
        nFlags |= 0x100;
    }

    nLevel = pRequest->nRequestLevel;
    if (nLevel < -1) {
        nLevel = -1;
    }
    Ov002_SetCursorRequest((u16)nFlags, (u16)a1, (u16)a2, nLevel);
}
