/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov038_FreeFiveGlobalSubObjects();extern void Ov022_DestroyRoot();extern int data_ov038_020b4ca0;
void Ov038_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov038_FreeFiveGlobalSubObjects(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov038_020b4ca0 = 0;
}
