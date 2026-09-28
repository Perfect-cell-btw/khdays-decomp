extern int Obj_RenderModel();

struct S { int x[11]; };

int Ov277_RenderAtOwnerNode(int *a, int b) {
    char *p = *(char **)((char *)a + 0x84);
    p = *(char **)p;
    p = *(char **)(p + 0x3b0);
    *(struct S *)((char *)a + 0x30) = *(struct S *)(p + 0x4);
    return Obj_RenderModel(a, b);
}
