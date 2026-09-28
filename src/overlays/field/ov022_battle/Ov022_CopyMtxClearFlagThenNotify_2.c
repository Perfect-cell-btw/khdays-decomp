/* When the current sub-object belongs to the local player's side, copies the inverse camera matrix
 * into it, clears its aim flag and posts its update. */

extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int state);
extern int *G3d_GetInverseCameraMtx(void);
extern void MI_Copy36B(int *dst, int *src);
extern void func_ov022_0208ffe8(int a);

struct Mtx020900b8 { int w[12]; };

void Ov022_CopyMtxClearFlagThenNotify_2(int arg0) {
    int e = *(int *)(arg0 + *(int *)(arg0 + 0xc) * 4 + 0x18);
    int neg;
    struct Mtx020900b8 buf;
    if (*(signed char *)(e + 0x110) != Ov022_GetEntryField66(QueryActiveStateOrDelegate())) return;
    neg = -1;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == neg) return;
    buf = *(struct Mtx020900b8 *)G3d_GetInverseCameraMtx();
    MI_Copy36B((int *)&buf, (int *)(e + 0x88));
    *(unsigned short *)(e + 8) &= ~0x20;
    func_ov022_0208ffe8(e + 8);
}
