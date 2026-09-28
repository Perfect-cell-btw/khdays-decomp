
#include "nitro/types.h"

typedef struct Ov002TickCtx {
    int nFlags;
    int nLastMs;
    int nElapsed;
    int nTotal;
    int nRun;
    int nSplit;
    int aLaps[2];
} Ov002TickCtx;

extern Ov002TickCtx *data_ov002_0207fa08;

extern int Session_IsReady(void);          /* session ready */
extern int Ov002_AdvanceSlotPhase(u8 nCommand);

/* Starts or stops one of the two lap timers.  bStart picks the verb; nLap picks
   the lap, or -1 to take the first one whose armed bit is still clear.  Returns
   the lap it acted on, -1 when the request was refused, or 0 when the session is
   not ready yet. */
int Ov002_SetLapRunning(int bStart, int nLap)
{
    Ov002TickCtx *pCtx;
    int nKind;
    int k;

    pCtx = data_ov002_0207fa08;
    if (Session_IsReady() == 0) {
        return 0;
    }

    if (nLap == -1) {
        for (k = 0; k < 2; k++) {
            if (bStart != 0) {
                if ((pCtx->nFlags & (0x20 << k)) == 0) {
                    nLap = k;
                    break;
                }
            }
        }
    }

    if (nLap == -1) {
        pCtx->nFlags &= ~0x20;
        nLap = 0;
    }

    if (bStart != 0) {
        nKind = 5;
    } else {
        nKind = 6;
    }

    if (Ov002_AdvanceSlotPhase((u8)(nKind | (nLap << 6))) == 0) {
        return -1;
    }
    return nLap;
}
