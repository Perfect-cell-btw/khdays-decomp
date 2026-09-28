/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov057_FreeFiveGlobalSubObjects();extern void Ov022_DestroyRoot();extern int data_ov057_020b74a0;
void Ov057_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov057_FreeFiveGlobalSubObjects(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov057_020b74a0 = 0;
}
