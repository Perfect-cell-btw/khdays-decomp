/* When the object belongs to the local player's side, posts its update with its model's culling
 * adjusted for materials 2 and 3. */

extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int state);
extern void NNS_G3dMdlSetMdlCullMode(int a, int b, int c);
extern void func_ov022_0208ffe8(int a);

void Ov022_UpdateTracks23ByFlag(int arg0) {
    int e = *(int *)(arg0 + 0x44);
    int neg;
    if (*(signed char *)(e + 0x110) != Ov022_GetEntryField66(QueryActiveStateOrDelegate())) return;
    neg = -1;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == neg) return;
    NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 2, 0);
    NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 3, 0);
    if ((*(unsigned int *)(e + 0x158) & 1) != 0) {
        NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 2, 3);
        NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 3, 3);
    }
    func_ov022_0208ffe8(e + 8);
    NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 2, 3);
    NNS_G3dMdlSetMdlCullMode(*(int *)(e + 0x80), 3, 3);
}
