struct T { int a, b, c; };

struct S {
    char pad[0x10];
    struct T t;
    char pad2[0x28 - 0x1c];
    unsigned char flags;
};

void Srt_SetTranslation(struct S *dst, struct T *src)
{
    dst->t = *src;
    dst->flags &= ~1;
}
