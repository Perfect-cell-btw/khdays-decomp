/* Draws the character's effect objects while the owner is shown: the eight emitters, the node at
 * the owner, and the main effect at the owner's position when it is active. */

struct b1 { unsigned char b : 1; };
struct v3 { int a, b, c; };
extern void Ov063_DrawWithFadePolygonId(void *p);
extern void Ov063_DrawNodeAtOwner(void *this);
extern void Scene_DrawNode(void *p);

void Ov063_updateSubObjects(char *this) {
    char *g = *(char **)(this + 0xdb4);
    int i;
    char *p;
    if (((struct b1 *)(g + 0x694))->b == 0) return;
    p = this + 0x234;
    for (i = 0; i < 8; i++) {
        Ov063_DrawWithFadePolygonId(p);
        p += 0x170;
    }
    Ov063_DrawNodeAtOwner(this);
    if (*(int *)(this + 0x14) != 1) return;
    *(struct v3 *)(this + 0xbc) = *(struct v3 *)(g + 0x48c);
    Scene_DrawNode(this + 0x18);
}
