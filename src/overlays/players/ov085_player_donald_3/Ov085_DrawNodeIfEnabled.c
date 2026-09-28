/* While the character is shown and the effect node is visible, places it at the character's
 * position turned with the character and draws it. */

extern void Scene_DrawNode(int a);

typedef struct { int x, y, z; } Vec3;
typedef struct { unsigned char b0 : 1; } Flags;

typedef struct {
    char pad0[0x10];
    int kind;
    unsigned short flags;
    char pad16[0x7a];
    unsigned short angle;
    char pad92[0x26];
    Vec3 vec;
} Node;

void Ov085_DrawNodeIfEnabled(int self, Node *node) {
    Vec3 v;
    if (!((Flags *)(self + 0x694))->b0) return;
    if (node->kind != 2) return;
    v = *(Vec3 *)(self + 0x8c + 0x400);
    node->angle = (unsigned short)(*(unsigned short *)(*(int *)(self + 0x20) + 0x80) - 0x8000) + 0x8000;
    node->flags |= 0x20;
    node->vec = v;
    Scene_DrawNode((int)&node->flags);
}
