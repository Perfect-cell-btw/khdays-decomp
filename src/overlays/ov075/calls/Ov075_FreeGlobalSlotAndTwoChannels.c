extern void ReleaseField74AndCleanup(int p);
extern void func_ov022_02091228(int p);
extern int data_ov075_020b9e20;

void Ov075_FreeGlobalSlotAndTwoChannels(int this_) {
    ReleaseField74AndCleanup(data_ov075_020b9e20 + 0x2dac);
    func_ov022_02091228(*(int *)(this_ + 0x2644) + 0x30);
    func_ov022_02091228(*(int *)(this_ + 0x2644) + 0x60);
}
