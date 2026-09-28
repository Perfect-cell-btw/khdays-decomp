extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov293_CreateNamedEntity(int);

void Ov293_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6f, Ov293_CreateNamedEntity);
}
