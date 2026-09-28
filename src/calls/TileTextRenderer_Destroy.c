extern int NNSi_FndFreeFromDefaultHeap();

int TileTextRenderer_Destroy(int *r0)
{
    NNSi_FndFreeFromDefaultHeap(((int *)r0)[0x2c / 4]);
    return 1;
}
