/* Renders the object at its owner's position scaled to twice the owner's radius. */

struct T { int a, b, c; };

struct Xform {
    int m0[4];
    int m10[3];
    int f1c;
    int f20;
    int f24;
    unsigned char flags;
};

struct Obj84 {
    char pad[0x74];
    struct T t;
    int f80;
};

extern void SrtTransform_SetIdentity(struct Xform *o);
extern void Srt_SetScaleUniform(struct Xform *p, int v);
extern void Srt_SetTranslation(struct Xform *dst, struct T *src);
extern void Obj_RenderModel(void *self, int region);

void Ov107_RenderAtOwnerSphere(void *self, int region)
{
    struct Obj84 *p = *(struct Obj84 **)((char *)self + 0x84);
    struct Xform *xf = (struct Xform *)((char *)self + 0x30);

    if (p == 0) {
        return;
    }
    SrtTransform_SetIdentity(xf);
    Srt_SetScaleUniform(xf, p->f80 * 2);
    Srt_SetTranslation(xf, &p->t);
    Obj_RenderModel(self, region);
}
