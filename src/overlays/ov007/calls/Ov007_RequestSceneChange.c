extern char *NNSi_FndGetCurrentRootHeap(void);
extern void StoreGlobalPairAt10(int, int);

int Ov007_RequestSceneChange(void)
{
    char *p = NNSi_FndGetCurrentRootHeap();
    int r1 = *(int *)(p + 0x5000 + 0xac0);
    StoreGlobalPairAt10(5, r1);
    return ~1;
}
