/* Refreshes the child selector and runs the tick, then refreshes the anchor point (raised 0x2000
 * while airborne) and its 0x2000 radius. */

extern int Ov107_RefreshAndSelectChild();
extern int Ov107_ProcessObjectTick();

struct V {
    int a;
    int b;
    int c;
};

struct S {
    char pad0[0x60];
    unsigned short n60 : 8;
    unsigned short n60b : 8;
    char pad1[0xb0 - 0x62];
    struct V vb0;
    char pad3[0x3f0 - 0xbc];
    struct V v3f0;
    char pad4[0x490 - 0x3fc];
    void *p490;
    struct V v494;
    int n4a0;
};

void Ov249_TickAndUpdateAnchor(struct S *r4, int r5) {
    Ov107_RefreshAndSelectChild(r4->p490, r5);
    Ov107_ProcessObjectTick(r4, r5);
    if (r4->n60 & 0x80) {
        r4->v494 = r4->vb0;
        *(int *)((char *)r4 + 0x498) += 0x2000;
    } else {
        r4->v494 = r4->v3f0;
    }
    r4->n4a0 = 0x2000;
}
