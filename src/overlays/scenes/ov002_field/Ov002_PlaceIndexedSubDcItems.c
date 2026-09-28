/* Acquire and place up to five indexed sub-display resources. */
#include "nitro/types.h"

extern u16 data_ov002_0207db84[];
extern int Ov002_ForwardToSubDc(int nId);
extern int Ov002_PositionSubDcHandle_3(int nHandle, int nPosition, int nMode);

void Ov002_PlaceIndexedSubDcItems(signed char *pIndices)
{
    int i = 0;
    int nOffset = 0;

    do {
        if (pIndices[i] < 0) {
            return;
        }
        Ov002_PositionSubDcHandle_3(
            Ov002_ForwardToSubDc(data_ov002_0207db84[pIndices[i]]),
            (short)(0x1e - nOffset), 4);
        i++;
        nOffset += 2;
    } while (i < 5);
}
