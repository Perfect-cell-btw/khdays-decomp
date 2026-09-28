extern int NNSi_FndGetCurrentRootHeap();extern void Ov047_ReleaseGlobalAndSubObjectChannel();extern void Ov022_DestroyRoot();extern int data_ov047_020b4380;
void Ov047_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov047_ReleaseGlobalAndSubObjectChannel(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov047_020b4380 = 0;
}
