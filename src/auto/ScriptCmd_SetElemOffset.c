/* Script command: sets the current element's +0x10 to its base plus the operand; returns 2. */

struct Elem {
    char pad[0xc];
    int field_c;
    int field_10;
    char pad2[0x48 - 0x14];
};

struct Obj {
    int pad0;
    struct Elem elems[1];
    int index_124;
};

int ScriptCmd_SetElemOffset(struct Obj *obj, int *p) {
    int idx = *(int *)((char *)obj + 0x124);
    struct Elem *e = &obj->elems[idx];
    e->field_10 = e->field_c + *p;
    return 2;
}
