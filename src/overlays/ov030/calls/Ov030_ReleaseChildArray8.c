extern void ReleaseField74AndCleanup(void *p);

struct Sub { char data[0x170]; };

struct Obj {
    char pad[0x234];
    struct Sub subs[8];
};

void Ov030_ReleaseChildArray8(struct Obj *obj) {
    int i;
    for (i = 0; i < 8; i++) {
        ReleaseField74AndCleanup(&obj->subs[i]);
    }
}
