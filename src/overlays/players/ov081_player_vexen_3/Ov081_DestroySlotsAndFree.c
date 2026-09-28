/* Frees the character's two effect streams and their buffer, then releases its seven effect
 * sequences. */

extern void func_ov022_02091228(int a);
extern void NNSi_FndFreeFromDefaultHeap(int a);
extern void ReleaseField74AndCleanup(int a);
extern int data_ov081_020b96e0;

void Ov081_DestroySlotsAndFree(int self) {
    int base = *(int *)&data_ov081_020b96e0 + 0x2c + 0x2c00;
    int i;
    func_ov022_02091228(*(int *)(self + 0x2000 + 0x644));
    func_ov022_02091228(*(int *)(self + 0x2000 + 0x644) + 0x30);
    NNSi_FndFreeFromDefaultHeap(*(int *)(self + 0x2000 + 0x644));
    for (i = 0; i < 7; i++) {
        ReleaseField74AndCleanup(base + 0x18 + i * 0x10c);
    }
}
