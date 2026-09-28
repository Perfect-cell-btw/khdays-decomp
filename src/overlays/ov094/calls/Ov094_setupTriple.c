extern int NNSi_FndGetCurrentRootHeap();extern void Ov094_FreeFiveGlobalSubObjects();extern void Ov022_DestroyRoot();extern int data_ov094_020bc240;
void Ov094_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov094_FreeFiveGlobalSubObjects(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov094_020bc240 = 0;
}
