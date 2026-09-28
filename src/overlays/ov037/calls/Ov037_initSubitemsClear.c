extern int NNSi_FndGetCurrentRootHeap();extern void Ov037_ReleaseAndFreeField2644();extern void Ov037_ReleaseBothSlots();extern void Ov022_DestroyRoot();extern int data_ov037_020b4e20;
void Ov037_initSubitemsClear(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov037_ReleaseAndFreeField2644(r);
    Ov037_ReleaseBothSlots(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov037_020b4e20 = 0;
}
