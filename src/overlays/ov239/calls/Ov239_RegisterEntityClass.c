extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov239_CreateNamedEntity(int);

void Ov239_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x42, Ov239_CreateNamedEntity);
}
