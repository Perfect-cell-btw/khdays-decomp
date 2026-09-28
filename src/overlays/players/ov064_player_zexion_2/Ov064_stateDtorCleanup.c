/* Tears the character down: releases the active widget sequence, frees the effect resources,
 * destroys the root object and clears the overlay's global pointer. */

extern int NNSi_FndGetCurrentRootHeap(void);
extern void ReleaseField74AndCleanup(int a);
extern void Ov064_ReleaseChannelListAndSubObjects(int a);
extern void Ov022_DestroyRoot(int a);
extern int data_ov064_020b7420;
void Ov064_stateDtorCleanup(void) {
    int obj = NNSi_FndGetCurrentRootHeap();
    if (*(int *)(obj + 0x2c2c) != 0) {
        ReleaseField74AndCleanup(obj + 0x2c30);
        *(int *)(obj + 0x2c2c) = 0;
    }
    Ov064_ReleaseChannelListAndSubObjects(obj);
    Ov022_DestroyRoot(obj);
    data_ov064_020b7420 = 0;
}
