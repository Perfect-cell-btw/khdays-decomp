extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov153_CreateNamedEntity(int);

void Ov153_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x14, Ov153_CreateNamedEntity);
}
