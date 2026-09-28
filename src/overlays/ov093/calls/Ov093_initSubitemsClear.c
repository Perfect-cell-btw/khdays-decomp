/* ov init (thumb): run 4 setup calls on the object then clear a global slot. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov093_ReleaseAndFreeField2644();extern void Ov093_ReleaseBothSlots();extern void Ov022_DestroyRoot();extern int data_ov093_020bc3c0;
void Ov093_initSubitemsClear(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov093_ReleaseAndFreeField2644(r);
    Ov093_ReleaseBothSlots(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov093_020bc3c0 = 0;
}
