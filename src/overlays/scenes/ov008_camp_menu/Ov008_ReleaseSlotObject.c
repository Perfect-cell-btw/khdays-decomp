/* Releases a live slot object (and its resources when it owns them) and clears it. */

#include "game/engine.h"

extern void NNSi_FndFreeFromDefaultHeap(void *block);

void Ov008_ReleaseSlotObject(void *object)
{
    if (*(signed char *)((char *)object + 1) != 0) {
        ReleaseField74AndCleanup((char *)object + 4);

        if ((*(unsigned char *)object & 4) != 0) {
            FreeAllResourceTables((char *)object + 0x13c);
            NNSi_FndFreeFromDefaultHeap(*(void **)((char *)object + 0x160));
        }

        *(unsigned char *)object = 0;
    }
}
