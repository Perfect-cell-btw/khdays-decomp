extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov130_CreateNamedEntity(int);

void Ov130_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x08, Ov130_CreateNamedEntity);
}
