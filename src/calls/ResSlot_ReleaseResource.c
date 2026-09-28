extern int ResGroup_Release(void *p);
extern int NNS_G3dResDefaultRelease(void *p);

struct S {
    short _0;
    unsigned short x2;
    unsigned short x4;
    char _6[6];
    void *xc;
};

int ResSlot_ReleaseResource(struct S *p)
{
    p->x2 = p->x2 - 1;
    if (p->x2 == 0) {
        if (*(int *)p->xc == 0x4850414B) {
            ResGroup_Release(p->xc);
        } else {
            NNS_G3dResDefaultRelease(p->xc);
        }
        p->x4 = 0;
        return 1;
    }
    return 0;
}
