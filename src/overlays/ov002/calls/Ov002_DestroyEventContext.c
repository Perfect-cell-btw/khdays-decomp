extern int NNSi_FndGetCurrentRootHeap();
extern int Ov002_ResetLinkState();
extern int data_ov002_0207fa04;

void Ov002_DestroyEventContext(int arg0) {
    NNSi_FndGetCurrentRootHeap(arg0);
    Ov002_ResetLinkState();
    data_ov002_0207fa04 = 0;
}
