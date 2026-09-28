extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov296_CreateNamedEntity(int);

void Ov296_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x70, Ov296_CreateNamedEntity);
}
