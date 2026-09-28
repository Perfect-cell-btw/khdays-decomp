extern int NNSi_FndGetCurrentRootHeap();extern void Ov056_ReleaseAndFreeField2644();extern void Ov056_ReleaseBothSlots();extern void Ov022_DestroyRoot();extern int data_ov056_020b7620;
void Ov056_initSubitemsClear(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov056_ReleaseAndFreeField2644(r);
    Ov056_ReleaseBothSlots(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov056_020b7620 = 0;
}
