/* Node destructor: releases and frees its animation sequence (+0x88), destroys and frees its
 * sorted-entry list (+0x90), then runs the base node destructor. */

extern void ReleaseField74AndCleanup();
extern void FreeInstanceMemory();
extern void NNSi_FndDestroyDoubleList();
extern void Node_BaseOnDestroy();

void DestroySubObjectsAndCleanup2(int this_) {
    ReleaseField74AndCleanup(*(int *)(this_ + 0x88));
    FreeInstanceMemory(*(int *)(this_ + 0x88));
    *(int *)(this_ + 0x88) = 0;
    if (*(int *)(this_ + 0x90) != 0) {
        NNSi_FndDestroyDoubleList(*(int *)(this_ + 0x90));
        FreeInstanceMemory(*(int *)(this_ + 0x90));
    }
    Node_BaseOnDestroy(this_);
}
