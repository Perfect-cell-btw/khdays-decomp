/* Sets an SRT's rotation quaternion and marks the rotation as non-identity. */

struct T { int a, b, c, d; };

struct S {
    struct T t;
    char pad[0x28 - 16];
    unsigned char flag;
};

int Srt_SetRotationQuat(struct S *dst, struct S *src)
{
    int v;
    dst->t = src->t;
    v = dst->flag & ~1;
    dst->flag = (unsigned char)v;
    return v;
}
