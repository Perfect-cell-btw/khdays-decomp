/* Releases the character's effect sequence, then frees its effect stream and buffer. */

extern int data_ov066_020b6b80;
extern void ReleaseField74AndCleanup();
extern void func_ov022_02091228();
extern void NNSi_FndFreeFromDefaultHeap();

void Ov066_ReleaseGlobalAndSubObjectChannel(int this_) {
    ReleaseField74AndCleanup(data_ov066_020b6b80 + 0x2c64);
    func_ov022_02091228(*(int *)(this_ + 0x2644));
    NNSi_FndFreeFromDefaultHeap(*(int *)(this_ + 0x2644));
}
