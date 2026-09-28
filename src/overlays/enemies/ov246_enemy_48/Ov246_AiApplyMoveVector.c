/* Copies the step's stored vector into the actor's movement vector (+0xf0). */

struct Vec3 {
    int x;
    int y;
    int z;
};

struct Src {
    int *base;
    int pad;
    struct Vec3 data;
};

struct Outer {
    int pad0;
    struct Src *src;
};

void Ov246_AiApplyMoveVector(struct Outer *p) {
    struct Src *s = p->src;
    *(struct Vec3 *)((char *)s->base + 0xf0) = s->data;
}
