extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov143_CreateNamedEntity(int);

void Ov143_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, Ov143_CreateNamedEntity);
}
