/* Release the sub-object held at +0x2644 through func_ov022_02091228, then free it. One of eight
 * byte-identical copies; see the ov007 twin. */

extern void func_ov022_02091228();extern void NNSi_FndFreeFromDefaultHeap();
void Ov076_ReleaseAndFreeField2644(int p) {
    func_ov022_02091228(*(int *)(p + 0x2644));
    NNSi_FndFreeFromDefaultHeap(*(int *)(p + 0x2644));
}
