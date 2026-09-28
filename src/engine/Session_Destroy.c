/* Tears the wireless session down: releases its two service instances and clears the session
 * pointer. */

extern int *NNSi_FndGetCurrentRootHeap(void);
extern void func_02023ad0(int arg);
extern int data_0204c228;

void Session_Destroy(void) {
    int *p = NNSi_FndGetCurrentRootHeap();
    func_02023ad0(p[9]);
    func_02023ad0(p[10]);
    data_0204c228 = 0;
}
