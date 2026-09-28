#include "nitro/types.h"

extern char *data_ov002_0207fa00;

extern void Utf8_ToUcs2(int nId, void *pRecord);
extern int LoadGlobalU16At0(void);
extern void Ov002_RequestPanelScreen(void *pRecord, u64 nScaled, int nSlot, int nFlags);
extern void Ov002_InstallPanelHandlers(void *pRecord);

/* Post a record for the given id. A non-negative amount is scaled and sent on
 * the normal path; a negative one falls back to the plain post, which is
 * suppressed in mode 0x2a. Nothing happens while the channel is unset. */
void Ov002_PostScoreRecord(int nId, int nAmount, int nSlot, int nFlags)
{
    char stk[0x100];

    if (*(int *)(data_ov002_0207fa00 + 0x8c94) == -1) {
        return;
    }

    Utf8_ToUcs2(nId, stk);

    if (nAmount >= 0) {
        Ov002_RequestPanelScreen(stk, (u64)((long long)nAmount * 0x82ea) >> 6,
                            nSlot, nFlags);
        return;
    }

    if (LoadGlobalU16At0() == 0x2a) {
        return;
    }

    Ov002_InstallPanelHandlers(stk);
}
