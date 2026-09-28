extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov165_CreateNamedEntity(int);

void Ov165_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, Ov165_CreateNamedEntity);
}
