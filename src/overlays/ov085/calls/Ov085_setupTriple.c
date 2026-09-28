extern int NNSi_FndGetCurrentRootHeap();extern void Ov085_ReleaseGlobalAndSubObjectChannel();extern void Ov022_DestroyRoot();extern int data_ov085_020b9260;
void Ov085_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov085_ReleaseGlobalAndSubObjectChannel(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov085_020b9260 = 0;
}
