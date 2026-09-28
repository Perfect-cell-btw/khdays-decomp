/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov103_ReleaseThreeSubBlocks2c2c();extern void Ov022_DestroyRoot();extern int data_ov103_020bc120;
void Ov103_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov103_ReleaseThreeSubBlocks2c2c(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov103_020bc120 = 0;
}
