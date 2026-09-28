/* Release one element: clear +0x24 bit1, free heap alloc at +0x2c (if set) and null it. */

extern int NNSi_FndFreeFromDefaultHeap();

struct S {
    char pad24[0x24];
    unsigned char flags;   /* 0x24 */
    char pad25[0x2c - 0x25];
    void *ptr;             /* 0x2c */
};

void Ov002_ReleaseElement(int a, struct S *s) {
    s->flags &= ~2;
    if (s->ptr != 0) {
        NNSi_FndFreeFromDefaultHeap(s->ptr);
        s->ptr = 0;
    }
}
