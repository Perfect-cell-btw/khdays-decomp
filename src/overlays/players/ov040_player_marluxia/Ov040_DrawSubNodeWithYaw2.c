extern void func_ov022_020ad44c(void *out, int self);
extern void Scene_DrawNode(int a);

typedef struct { int x, y, z; } Vec3;

typedef struct {
    char pad0[0x34];
    int kind;
    unsigned short flags;
    char pad3a[0x7a];
    unsigned short angle;
    char padb6[0x26];
    Vec3 vec;
} Node;

typedef struct { char pad0[0x200]; Node node; } Block;

void Ov040_DrawSubNodeWithYaw2(int self, Block *b) {
    Vec3 v;
    if (b->node.kind != 1 && b->node.kind != 2 && b->node.kind != 3) return;
    func_ov022_020ad44c(&v, self);
    b->node.angle = (unsigned short)(*(unsigned short *)(*(int *)(self + 0x20) + 0x80) - 0x8000) + 0x8000;
    b->node.flags |= 0x20;
    b->node.vec = v;
    Scene_DrawNode((int)&b->node.flags);
}
