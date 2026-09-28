#include "game/ov008_camp_menu.h"
/* Copies a peer's uploaded slot data out and clears its pending flag. */

extern void MI_CpuCopy8(void *src, void *dst, int size);

void Ov008_UploadSlotTiles(int index, void *dst, int size)
{
    if (dst != 0) {
        MI_CpuCopy8(*(void **)((char *)data_ov008_02090f24.pContext + index * 8 + 8), dst, size);
    }

    *(int *)((char *)data_ov008_02090f24.pContext + index * 4 + 0x30) = 0;
}
