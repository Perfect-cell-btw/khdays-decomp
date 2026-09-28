/* Sets a transform's base position (+0x48). */

struct T { int a, b, c; };
struct S { int pad[18]; struct T t; };

void Transform_SetBasePos(struct S *d, struct T *s)
{
    d->t = *s;
}
