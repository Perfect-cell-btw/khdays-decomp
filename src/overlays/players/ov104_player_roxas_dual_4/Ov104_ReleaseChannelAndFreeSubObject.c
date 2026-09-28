/* Frees the character's effect stream and buffer, then releases its effect sequence. */

extern void func_ov022_02091228(int p);
extern void NNSi_FndFreeFromDefaultHeap(int p);
extern void ReleaseField74AndCleanup(int p);
extern int data_ov104_020bc2a0;

void Ov104_ReleaseChannelAndFreeSubObject(int this_) {
    char *base = (char *)(data_ov104_020bc2a0 + 0x2cfc);
    func_ov022_02091228(*(int *)(this_ + 0x2644));
    NNSi_FndFreeFromDefaultHeap(*(int *)(this_ + 0x2644));
    ReleaseField74AndCleanup((int)(base + 4));
}
