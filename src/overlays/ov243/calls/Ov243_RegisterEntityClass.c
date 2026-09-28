extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov243_CreateNamedEntity(int);

void Ov243_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x45, Ov243_CreateNamedEntity);
}
