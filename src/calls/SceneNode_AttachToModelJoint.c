extern void INITi_CpuClear32_0x01ff86fc(unsigned int data, void *dst, unsigned int size);
extern void SceneNode_Detach(void *p);
extern void strcpy(void *dst, void *src);
extern int NNS_G3dGetResDictIdxByName(void *p, void *q);

extern char data_0204c1f8[];

void SceneNode_AttachToModelJoint(void *a0, void *a1, void *a2) {
    int r;
    void *p;

    if (((void **)a0)[0xbc / 4] != (void *)0) {
        SceneNode_Detach(a0);
    }
    if (a1 == (void *)0) return;

    INITi_CpuClear32_0x01ff86fc(0, data_0204c1f8, 0x10);
    strcpy(data_0204c1f8, a2);

    p = ((void **)a1)[0x24 / 4];
    p = p ? (void *)((char *)p + 0x40) : (void *)0;
    if (p == (void *)0) {
        r = -1;
    } else {
        r = NNS_G3dGetResDictIdxByName(p, data_0204c1f8);
    }
    *(unsigned short *)((char *)a0 + 0xc8) = (unsigned short)r;

    {
        void *q = ((void **)a1)[0xc0 / 4];
        if (q != (void *)0) ((void **)a0)[0xc4 / 4] = q;
    }
    ((void **)a1)[0xc0 / 4] = a0;
    ((void **)a0)[0xbc / 4] = a1;
}
