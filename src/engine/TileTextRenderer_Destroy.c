/* Frees a tile text renderer's buffer (+0x2c); returns 1. */

extern int NNSi_FndFreeFromDefaultHeap();

int TileTextRenderer_Destroy(void *pR0)
{
    int *r0 = (int *)pR0;
    NNSi_FndFreeFromDefaultHeap(((int *)r0)[0x2c / 4]);
    return 1;
}
