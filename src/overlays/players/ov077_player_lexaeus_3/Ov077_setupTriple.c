/* ov setup (thumb): 3 chained setup calls with computed offsets/args. */

extern int NNSi_FndGetCurrentRootHeap();extern void Ov077_FreeFiveGlobalSubObjects();extern void Ov022_DestroyRoot();extern int data_ov077_020b9b80;
void Ov077_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov077_FreeFiveGlobalSubObjects(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov077_020b9b80 = 0;
}
