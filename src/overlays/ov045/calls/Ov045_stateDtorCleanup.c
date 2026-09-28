extern int NNSi_FndGetCurrentRootHeap(void);
extern void ReleaseField74AndCleanup(int a);
extern void Ov045_ReleaseChannelListAndSubObjects(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov045_020b4c20;
void Ov045_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    if (*(int *)(obj + 0x2c2c) != 0) {
        ReleaseField74AndCleanup(obj + 0x2c30);
        *(int *)(obj + 0x2c2c) = 0;
    }
    Ov045_ReleaseChannelListAndSubObjects(obj);
    Ov022_DestroyRoot(obj);
    data_ov045_020b4c20 = 0;
}
