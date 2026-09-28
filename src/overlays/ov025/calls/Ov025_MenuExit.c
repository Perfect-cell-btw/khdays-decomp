extern int NNSi_FndGetCurrentRootHeap();
extern int Ov025_PageTeardown();
extern int data_ov025_020b49c0;
extern int data_ov025_020b5740;

void Ov025_MenuExit(int arg0) {
    NNSi_FndGetCurrentRootHeap(arg0);
    Ov025_PageTeardown(0);
    data_ov025_020b49c0 = -1;
    data_ov025_020b5740 = 0;
}
