/* 0xd90 and 0xda0 are 0x10 apart -- two adjacent sub-objects, so an array of two,
 * not two unrelated fields. */
typedef struct {
    char pad00[0x10];
} Ov022Sub;

typedef struct {
    int flags;        /* +0x00 */
    char pad04[0x30];
    int f34;          /* +0x34 */
    int f38;          /* +0x38 */
} Ov022Inner;

typedef struct {
    char pad000[0x20];
    char *owner;          /* +0x20; the inner block starts at owner+0x24 */
    char padd24[0xd6c];
    Ov022Sub sub[2];      /* +0xd90, +0xda0 */
    char paddb0[0x18bc];
    char pad266c[0];      /* +0x266c is a sub-struct, +0x2684 a heap pointer */
} Ov022Root;

extern void ConstReturn1(void *p);
extern void NNS_G3dRenderObjResetCallBack(Ov022Inner *p);
extern void NNSi_FndFreeFromDefaultHeap(void *p);
extern void Ov022_ReleaseAllSubsystems(void *p);
extern void Ov022_CommitPanes(void *p);
extern void Ov022_ReleaseIfFlags(void *p);
extern void Ov022_RecueTrack(void *p);
extern void func_ov022_0209f0b8(void *p);
extern void func_ov022_0209cc68(void *p);
extern void func_ov022_0209d278(void *p);

void Ov022_DestroyRoot(char *root) {
    Ov022Inner *in;

    ConstReturn1(root + 0x266c);
    NNS_G3dRenderObjResetCallBack((Ov022Inner *)(*(char **)(root + 0x20) + 0x24));
    in = (Ov022Inner *)(*(char **)(root + 0x20) + 0x24);
    if (in->f38 == 0) {
        in->flags &= ~1;
    }
    in->f34 = 0;
    NNSi_FndFreeFromDefaultHeap(*(void **)(root + 0x2684));
    Ov022_ReleaseAllSubsystems(root);
    Ov022_CommitPanes(root);
    Ov022_ReleaseIfFlags(root + 0xd90);
    Ov022_RecueTrack(root + 0xda0);
    func_ov022_0209f0b8(root);
    func_ov022_0209cc68(root);
    func_ov022_0209d278(root);
}
