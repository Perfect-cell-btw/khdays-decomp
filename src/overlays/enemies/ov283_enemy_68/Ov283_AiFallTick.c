/* Applies gravity and damping; lands when the animation ends and grounded. */

struct vec3 { int x, y, z; };
struct b1 { unsigned char b:1; };

extern void ScaleVec3Fx12(int factor, int *src, int *dst);
extern void Ov107_PostTagUpdate(int obj, int a, int b);
extern void SetIndexedSlot(int obj, int a, int cb);
extern void Ov283_AiFallTickB(void);

void Ov283_AiFallTick(int *this) {
    int node = this[1];
    struct vec3 *v = (struct vec3 *)(node + 0x1c);
    *(struct vec3 *)(node + 0x10) = *v;
    *(int *)(node + 0x14) = *(int *)(node + 0x58);
    *(int *)(node + 0x58) = *(int *)(node + 0x58) - 0x80;
    ScaleVec3Fx12(0xe00, (int *)v, (int *)v);

    if (*(unsigned char *)(*(int *)(node + 4) + 0xad) != 0) {
        int obj = *(int *)node;
        if (!((struct b1 *)(obj + 0x17a))->b) {
            return;
        }
    }

    Ov107_PostTagUpdate(*(int *)node, 4, 0);
    SetIndexedSlot((int)this, *(signed char *)((int)this + 0x20), (int)&Ov283_AiFallTickB);
}
