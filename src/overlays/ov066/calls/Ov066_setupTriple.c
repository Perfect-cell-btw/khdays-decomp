extern int NNSi_FndGetCurrentRootHeap();extern void Ov066_ReleaseGlobalAndSubObjectChannel();extern void Ov022_DestroyRoot();extern int data_ov066_020b6b80;
void Ov066_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov066_ReleaseGlobalAndSubObjectChannel(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov066_020b6b80 = 0;
}
