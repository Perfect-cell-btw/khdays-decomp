/* Renders the object at its owner's model: copies the owner model's 44-byte transform block (+0x30)
 * into the object, then draws it (Obj_RenderModel). */

extern int Obj_RenderModel();

struct S { int x[11]; };

int Ov132_RenderAtOwnerModel(int *a, int b) {
    char *p = *(char **)((char *)a + 0x84);
    p = *(char **)p;
    p = *(char **)(p + 0x384);
    *(struct S *)((char *)a + 0x30) = *(struct S *)(p + 0x30);
    return Obj_RenderModel(a, b);
}
