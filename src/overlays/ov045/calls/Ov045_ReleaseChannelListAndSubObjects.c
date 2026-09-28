extern void func_ov022_02091228(int p);
extern void NNSi_FndFreeFromDefaultHeap(int p);
extern void Ov002_FreeResourceTables(int a, int b);
extern void ReleaseField74AndCleanup(int p);

void Ov045_ReleaseChannelListAndSubObjects(int this_) {
    func_ov022_02091228(*(int *)(this_ + 0x2644));
    NNSi_FndFreeFromDefaultHeap(*(int *)(this_ + 0x2644));
    Ov002_FreeResourceTables(this_ + 0x2d38, this_ + 0x910);
    Ov002_FreeResourceTables(this_ + 0x2d8c, this_ + 0x910);
    ReleaseField74AndCleanup(this_ + 0x2df4);
}
