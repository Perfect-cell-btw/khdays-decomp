/* Releases the service class instance, if any, and forgets its id. */

extern void func_02023ad0(int arg);

extern int data_02042978;

void ReleaseServiceInstance(void) {
    if (data_02042978 == -1) return;
    func_02023ad0(data_02042978);
    data_02042978 = -1;
}
