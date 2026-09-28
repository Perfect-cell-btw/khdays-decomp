extern void VEC_Add(const void *a, const void *b, void *ab);
extern void Scene_DrawNode(int a);

typedef struct { int x, y, z; } Vec3;

typedef struct {
    int kind;
    unsigned short flags;
    char pad6[0x7a];
    unsigned short angle;
    char pad82[0x26];
    Vec3 vec;
    char padb4[0x110 - 0xb4];
    Vec3 off;
} Node;

void Ov075_DrawNodeWithOffsetPos(int self, Node *node) {
    Vec3 v;
    unsigned short a;
    if (node->kind != 2 && node->kind != 3) return;
    v = *(Vec3 *)(self + 0x8c + 0x400);
    a = *(unsigned short *)(*(int *)(self + 0x20) + 0x80);
    VEC_Add(&node->off, &v, &v);
    node->angle = (unsigned short)(a - 0x8000) + 0x8000;
    node->flags |= 0x20;
    node->vec = v;
    Scene_DrawNode((int)&node->flags);
}
