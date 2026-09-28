extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov195_CreateNamedEntity(int);

void Ov195_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x24, Ov195_CreateNamedEntity);
}
