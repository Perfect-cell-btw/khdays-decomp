/* Field class pfnMethod: runs the pending steps, releases the handles and lists, frees the buffers
 * and clears the instance. */

typedef struct { void *f0; void *f4; void *f8; } Step;

extern void *NNSi_FndGetCurrentRootHeap(void);
extern void ZeroHalfThenFree(void *p);
extern void FreeInstanceMemory(void *p);
extern void *List_First(void *list);
extern void *List_Next(void *list);
extern void NNSi_FndDestroyDoubleList(void *list);
extern void Ov107_ReleaseLoadedResources(void);
extern void ClearGlobalArrayInt(int a);

extern void *data_ov107_020cbf1c;

void Ov107_FieldClassTeardown(void) {
    char *root;
    int i;
    char *p;
    void **node;

    root = (char *)NNSi_FndGetCurrentRootHeap();
    i = 0;
    p = root;
    for (; i < 4; i++) {
        Step *s = *(Step **)(p + 0x2c);
        if (s->f4 == 0 && s->f8 != 0) {
            ((void (*)(Step *))s->f8)(s);
        }
        p += 4;
    }
    ZeroHalfThenFree(*(void **)(root + 0x7c));
    ZeroHalfThenFree(*(void **)(root + 0x80));
    ZeroHalfThenFree(*(void **)(root + 0x84));
    ZeroHalfThenFree(*(void **)(root + 0x88));
    {
        Step *v = *(Step **)root;
        if (v->f8 != 0) {
            ((void (*)(Step *))v->f8)(v);
        }
    }
    node = (void **)List_First(root + 0x4c);
    while (node != 0) {
        ZeroHalfThenFree(node[0]);
        FreeInstanceMemory(node[1]);
        node = (void **)List_Next(root + 0x4c);
    }
    NNSi_FndDestroyDoubleList(root + 0x4c);
    NNSi_FndDestroyDoubleList(root + 4);
    if (*(void **)(root + 0x48) != 0) {
        FreeInstanceMemory(*(void **)(root + 0x48));
    }
    *(int *)(root + 0x48) = 0;
    Ov107_ReleaseLoadedResources();
    ClearGlobalArrayInt(1);
    ClearGlobalArrayInt(4);
    data_ov107_020cbf1c = 0;
}
