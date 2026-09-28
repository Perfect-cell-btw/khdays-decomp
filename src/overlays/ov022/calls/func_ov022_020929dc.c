extern void NNS_G3dRenderObjResetCallBack(int arg0);
extern void ReleaseField74AndCleanup(int arg0);
extern void FreeAllResourceTables(int arg0);
extern void NNSi_FndFreeFromDefaultHeap(int arg0);
extern void Ov022_ClearByte0AndByte0x135(int arg0);

void func_ov022_020929dc(unsigned char *arg0, int arg1, int arg2, int arg3) {
    if ((*arg0 & 1) != 0) {
        NNS_G3dRenderObjResetCallBack((int)(arg0 + 0x24));
        ReleaseField74AndCleanup((int)(arg0 + 4));
        FreeAllResourceTables((int)(arg0 + 0x10c));
        NNSi_FndFreeFromDefaultHeap(*(int *)(arg0 + 0x130));
        Ov022_ClearByte0AndByte0x135((int)arg0);
    }
}
