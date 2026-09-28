extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov151_CreateNamedEntity(int);

void Ov151_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x13, Ov151_CreateNamedEntity);
}
