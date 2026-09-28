extern void func_02023ad0();
extern int data_ov025_020b49c0;

void Ov025_EndKeySharingIfOpen(void) {
    int v = data_ov025_020b49c0;
    if (v == -1) {
        return;
    }
    func_02023ad0(v);
}
