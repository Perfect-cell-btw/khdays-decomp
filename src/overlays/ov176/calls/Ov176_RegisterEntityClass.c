extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov176_CreateNamedEntity(int);

void Ov176_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1e, Ov176_CreateNamedEntity);
}
