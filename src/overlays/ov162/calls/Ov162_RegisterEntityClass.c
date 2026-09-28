extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov162_CreateNamedEntity(int);

void Ov162_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x18, Ov162_CreateNamedEntity);
}
