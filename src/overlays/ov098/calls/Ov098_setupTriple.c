extern int NNSi_FndGetCurrentRootHeap();extern void Ov098_DestroySlotsAndFree();extern void Ov022_DestroyRoot();extern int data_ov098_020bbda0;
void Ov098_setupTriple(int p) {
    int r = NNSi_FndGetCurrentRootHeap(p);
    Ov098_DestroySlotsAndFree(r);
    Ov022_DestroyRoot(r);
    *(int *)&data_ov098_020bbda0 = 0;
}
