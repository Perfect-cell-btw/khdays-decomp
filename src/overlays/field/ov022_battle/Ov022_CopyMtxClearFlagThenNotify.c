/* When the object belongs to the local player's side and is active, copies the inverse camera
 * matrix into it, clears its aim flag and posts its update. */

extern int QueryActiveStateOrDelegate(void);
extern int Ov022_GetEntryField66(int state);
extern int *G3d_GetInverseCameraMtx(void);
extern void MI_Copy36B(int *dst, int *src);
extern void func_ov022_0208ffe8(int a);

struct Sel0208b2a8 { unsigned char sel : 3; };
struct Mtx0208b2a8 { int w[12]; };

void Ov022_CopyMtxClearFlagThenNotify(int arg0) {
    unsigned char *pb = *(unsigned char **)(arg0 + 0x148);
    unsigned int mode = *(unsigned char *)(arg0 + 0x14c);
    int neg;
    struct Mtx0208b2a8 buf;
    if (mode == 0 || mode == 4) return;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) !=
        ((struct Sel0208b2a8 *)(arg0 + 0x14d))->sel) return;
    neg = -1;
    if (Ov022_GetEntryField66(QueryActiveStateOrDelegate()) == neg) return;
    if (*pb >= 6 && *pb <= 8 && *(unsigned char *)(arg0 + 0x14c) == 1) return;
    buf = *(struct Mtx0208b2a8 *)G3d_GetInverseCameraMtx();
    MI_Copy36B((int *)&buf, (int *)(arg0 + 0x9c));
    *(unsigned short *)(arg0 + 0x1c) &= ~0x20;
    func_ov022_0208ffe8(arg0 + 0x1c);
}
