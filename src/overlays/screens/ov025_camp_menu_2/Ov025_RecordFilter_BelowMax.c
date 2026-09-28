/* Record filter: true for an enabled record whose maximum is below the value. */

struct S {
    char pad0[8];
    unsigned short h;
    char pad1[0x19];
    unsigned char b;
};

int Ov025_RecordFilter_BelowMax(struct S *p, unsigned int n) {
    if (p->b != 0) {
        return 0;
    }
    return p->h < n;
}
