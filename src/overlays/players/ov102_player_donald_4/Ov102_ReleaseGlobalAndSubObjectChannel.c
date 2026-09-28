extern int data_ov102_020bb920;
extern void ReleaseField74AndCleanup();
extern void func_ov022_02091228();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov102_ReleaseGlobalAndSubObjectChannel(int this_) {
    ReleaseField74AndCleanup(data_ov102_020bb920 + 0x2c64);
    func_ov022_02091228(*(int *)(this_ + 0x2644));
    NNSi_FndFreeFromDefaultHeap(*(int *)(this_ + 0x2644));
}
