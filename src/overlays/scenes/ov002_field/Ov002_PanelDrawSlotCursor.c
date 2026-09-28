/* Redraw the two-row cursor frame over one panel slot. Both rows are blanked
 * first, then eight tile pairs are written starting at the slot's base tile;
 * the flag shifts the frame one cell further left. The 0xffff slot is the
 * "no slot" sentinel and only clears. */
#include "nitro/types.h"

extern void MIi_CpuClear16(int nValue, void *pDest, int nSize);
extern void *Ov002_GetItemResource(int nResource);
extern void Ov002_SelectEntry(int nId);

void Ov002_PanelDrawSlotCursor(unsigned int nSlot, int nShift) {
    char *pRes;
    int wTop;
    int i;
    int wBottom;

    wTop = (u16)(nSlot * 0x10 + 0x250);
    pRes = (char *)Ov002_GetItemResource(9);

    if (nShift != 0) {
        nShift = -2;
    } else {
        nShift = -1;
    }

    MIi_CpuClear16(0, pRes + 0x202, 0x14);
    MIi_CpuClear16(0, pRes + 0x242, 0x14);

    if (nSlot < 0xffff) {
        wBottom = wTop + 8;
        for (i = 0; i < 8; i++) {
            *(u16 *)(pRes + (i + 0x103 + nShift) * 2) = (u16)(wTop | 0xf000);
            *(u16 *)(pRes + (i + 0x123 + nShift) * 2) = (u16)(wBottom | 0xf000);
            wTop++;
            wBottom++;
        }
    }

    Ov002_SelectEntry(9);
}
