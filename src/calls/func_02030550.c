extern int *NNSi_FndGetCurrentRootHeap(void);
extern void func_02023ad0(int arg);
extern int data_0204c228;

void func_02030550(void) {
    int *p = NNSi_FndGetCurrentRootHeap();
    func_02023ad0(p[9]);
    func_02023ad0(p[10]);
    data_0204c228 = 0;
}
