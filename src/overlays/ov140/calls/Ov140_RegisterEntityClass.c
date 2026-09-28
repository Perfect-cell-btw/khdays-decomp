extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov140_CreateNamedEntity(int);

void Ov140_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0c, Ov140_CreateNamedEntity);
}
