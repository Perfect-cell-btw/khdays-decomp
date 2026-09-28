extern void func_02023ad0(int *ctx);
extern int StoreGlobalArrayEntry(int idx, int value);
extern int *data_ov002_0207fa20;
/* Reset the subsystem: run teardown on the global context and clear global array entry 4; return 1. */
int Ov002_ResetSubsystem(void) {
    func_02023ad0(data_ov002_0207fa20);
    StoreGlobalArrayEntry(4, 0);
    return 1;
}
