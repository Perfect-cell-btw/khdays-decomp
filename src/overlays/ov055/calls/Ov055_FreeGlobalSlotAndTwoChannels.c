extern void ReleaseField74AndCleanup(int p);
extern void func_ov022_02091228(int p);
extern int data_ov055_020b7740;

void Ov055_FreeGlobalSlotAndTwoChannels(int this_) {
    ReleaseField74AndCleanup(data_ov055_020b7740 + 0x2dac);
    func_ov022_02091228(*(int *)(this_ + 0x2644) + 0x30);
    func_ov022_02091228(*(int *)(this_ + 0x2644) + 0x60);
}
