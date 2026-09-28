
#include "nitro/types.h"

extern char *data_ov002_0207fa00;

extern void Utf8_ToUcs2(int nId, void *pRecord);
extern int LoadGlobalU16At0(void);
extern void Ov002_RequestPanelScreen(u16 *pText, u32 nHoldLo, u32 nHoldHi, int bTextHandOff,
                                     int nItemId);
extern void Ov002_InstallPanelHandlers(void *pRecord);

/* The score as a hold time in ticks: amount * 0x82ea / 64, a 64-bit value. */
#define HOLD_TICKS(nAmount) ((u64)((long long)(nAmount) * 0x82ea) >> 6)

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
        Ov002_RequestPanelScreen((u16 *)stk, (u32)HOLD_TICKS(nAmount),
                                 (u32)(HOLD_TICKS(nAmount) >> 32), nSlot, nFlags);
        return;
    }

    if (LoadGlobalU16At0() == 0x2a) {
        return;
    }

    Ov002_InstallPanelHandlers(stk);
}
