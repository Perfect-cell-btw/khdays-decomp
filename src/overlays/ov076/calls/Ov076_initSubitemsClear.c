extern int NNSi_FndGetCurrentRootHeap();extern void Ov076_ReleaseAndFreeField2644();extern void Ov076_ReleaseBothSlots();extern void Ov022_DestroyRoot();extern int data_ov076_020b9d00;
void Ov076_initSubitemsClear(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov076_ReleaseAndFreeField2644(r);
    Ov076_ReleaseBothSlots(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov076_020b9d00 = 0;
}
