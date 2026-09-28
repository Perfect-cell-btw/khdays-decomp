extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov163_CreateNamedEntity(int);

void Ov163_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, Ov163_CreateNamedEntity);
}
