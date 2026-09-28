extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov205_CreateNamedEntity(int);

void Ov205_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x28, Ov205_CreateNamedEntity);
}
