extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov298_CreateNamedEntity(int);

void Ov298_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x72, Ov298_CreateNamedEntity);
}
