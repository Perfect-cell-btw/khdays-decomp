extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov291_CreateNamedEntity(int);

void Ov291_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6d, Ov291_CreateNamedEntity);
}
