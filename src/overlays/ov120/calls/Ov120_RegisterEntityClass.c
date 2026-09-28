extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov120_CreateNamedEntity(int);

void Ov120_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, Ov120_CreateNamedEntity);
}
