extern int NNS_G3dRenderObjInit();
extern int Snd_RegisterSeqAndBind();
extern int FreeAllResourceTables();
extern int MainBlob_ResetSlotRows();
extern int SetSubitemState();

struct B {
    char pad[0x78];
    int f78;
};

struct A {
    char pad[0x88];
    struct B *b;
};

int Ov209_BindClip(struct A *a, int b, int c, int *d)
{
    struct B *p;

    FreeAllResourceTables(d);
    d[3] = 0;
    p = a->b;
    NNS_G3dRenderObjInit((char *)p + 0x20, p->f78);
    Snd_RegisterSeqAndBind(d, p, b, 0xc);
    MainBlob_ResetSlotRows(a, d);
    return SetSubitemState(a, 0, 0, c);
}
