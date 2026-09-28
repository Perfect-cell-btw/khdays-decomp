extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov131_CreateNamedEntity(int);

void Ov131_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x09, Ov131_CreateNamedEntity);
}
