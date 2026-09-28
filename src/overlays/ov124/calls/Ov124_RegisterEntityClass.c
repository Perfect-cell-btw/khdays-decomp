extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov124_CreateNamedEntity(int);

void Ov124_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x05, Ov124_CreateNamedEntity);
}
