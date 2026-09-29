#include "game/engine.h"

extern char *data_ov002_0207fa00;

extern void Ov002_SetSessionActive(int nKind, int nValue);
extern void MIi_CpuClear16(unsigned short nValue, void *pDest, int nSize);

/* Reset the pending-id list and re-arm its timer. The eight slots are blanked
 * to 0xffff first, then the caller's ids are narrowed into them. */
void Ov002_ResetPendingIds(const int *pIds, int nCount)
{
    char *pBlock;
    int i;
    char *pSlot;

    pBlock = *(char **)&data_ov002_0207fa00 + 0x8c94;

    PauseMenu_SetAllowed(0);
    Ov002_SetSessionActive(1, 0xff);
    MIi_CpuClear16(0xffff, pBlock + 0x52, 0x10);

    i = 0;
    if (nCount > 0) {
        pSlot = pBlock;
        do {
            *(short *)(pSlot + 0x52) = (short)*pIds;
            i++;
            pIds++;
            pSlot += 2;
        } while (i < nCount);
    }

    *(int *)(pBlock + 0x64) = GetMasterBrightnessMain() << 12;
    *(unsigned char *)(pBlock + 0x51) = 0;
    *(unsigned char *)(pBlock + 0x68) = 0;
}
