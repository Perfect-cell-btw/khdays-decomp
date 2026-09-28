extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov164_CreateNamedEntity(int);

void Ov164_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, Ov164_CreateNamedEntity);
}
