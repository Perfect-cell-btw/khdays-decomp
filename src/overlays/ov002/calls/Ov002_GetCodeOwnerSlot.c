extern int Ov002_FindCodeOwner();

int Ov002_GetCodeOwnerSlot(int arg0) {
    int b;
    int a;
    Ov002_FindCodeOwner(*(signed char *)(arg0 + 1), &b, &a);
    return a;
}
