extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov250_CreateNamedEntity(int);

void Ov250_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x4b, Ov250_CreateNamedEntity);
}
