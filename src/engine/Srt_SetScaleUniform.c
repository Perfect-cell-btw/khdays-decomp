/* Sets an SRT's scale to the same value on every axis and marks it uniform. */

struct S {
    int pad[7];
    int a;       /* 0x1c */
    int b;       /* 0x20 */
    int c;       /* 0x24 */
    unsigned char f0 : 1;  /* 0x28 bit0 */
    unsigned char f1 : 1;  /* 0x28 bit1 */
};

void Srt_SetScaleUniform(struct S *p, int v) {
    p->a = v;
    p->b = v;
    p->c = v;
    p->f0 = 0;
    p->f1 = 1;
}
