/* Sets an SRT's scale from a vector and marks it non-identity and non-uniform. */

struct Vec3 { int x, y, z; };

struct Obj {
    char pad[0x1c];
    struct Vec3 v;
    unsigned char flags;
};

void Srt_SetScaleVec(struct Obj *o, struct Vec3 *src) {
    o->v = *src;
    o->flags &= ~1;
    o->flags &= ~2;
}
