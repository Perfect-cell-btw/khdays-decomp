/* When the effect node is in its visible state, places it at the attack anchor its kind names,
 * turned with the character, and draws it. */

extern void Ov058_GetAttackAnchor(int self, int kind, void *out);
extern void Scene_DrawNode(int a);

typedef struct { int x, y, z; } Vec3;

typedef struct {
    signed char f0;
    signed char f1;
    char pad2[2];
    unsigned short flags;
    char pad6[0x7a];
    unsigned short angle;
    char pad82[0x26];
    Vec3 vec;
} Node;

void Ov058_DrawNodeWithResolvedPos(int self, Node *node) {
    Vec3 v;
    if (node->f1 != 2) return;
    Ov058_GetAttackAnchor(self, node->f0, &v);
    node->angle = (unsigned short)(*(unsigned short *)(*(int *)(self + 0x20) + 0x80) - 0x8000) + 0x8000;
    node->flags |= 0x20;
    node->vec = v;
    Scene_DrawNode((int)&node->flags);
}
