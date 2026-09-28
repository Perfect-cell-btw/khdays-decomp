/* Node destructor: releases and frees its animation sequence (+0x88), frees its entry table
 * (+0x90), then runs the base node destructor. */

extern void ReleaseField74AndCleanup();
extern void FreeInstanceMemory();
extern void Node_BaseOnDestroy();

void DestroySubObjectsAndCleanup(int this_) {
    ReleaseField74AndCleanup(*(int *)(this_ + 0x88));
    FreeInstanceMemory(*(int *)(this_ + 0x88));
    if (*(int *)(this_ + 0x90) != 0) {
        FreeInstanceMemory(*(int *)(this_ + 0x90));
    }
    *(int *)(this_ + 0x90) = 0;
    *(int *)(this_ + 0x8c) = 0;
    Node_BaseOnDestroy(this_);
}
