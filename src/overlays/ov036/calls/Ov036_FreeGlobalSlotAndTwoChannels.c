extern void ReleaseField74AndCleanup(int p);
extern void func_ov022_02091228(int p);
extern int data_ov036_020b4f40;

void Ov036_FreeGlobalSlotAndTwoChannels(int this_) {
    ReleaseField74AndCleanup(data_ov036_020b4f40 + 0x2dac);
    func_ov022_02091228(*(int *)(this_ + 0x2644) + 0x30);
    func_ov022_02091228(*(int *)(this_ + 0x2644) + 0x60);
}
