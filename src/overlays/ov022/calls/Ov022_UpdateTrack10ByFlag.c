extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int state);
extern void NNS_G3dMdlSetMdlCullMode(int a, int b, int c);
extern void func_ov022_0208ffe8(int a);

struct Flags0208fd70 { unsigned char b0 : 1; unsigned char b1 : 1; };

void Ov022_UpdateTrack10ByFlag(int arg0) {
    int e = *(int *)(arg0 + *(int *)(arg0 + 0xc) * 4 + 0x18);
    int neg;
    if (*(signed char *)(e + 0x110) != Ov022_GetEntryField66(QueryActiveStateOrDelegate())) return;
    neg = -1;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == neg) return;
    NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 10, 0);
    if (((struct Flags0208fd70 *)(e + 0x134))->b1)
        NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 10, 3);
    func_ov022_0208ffe8(e + 8);
    NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 10, 3);
}
