extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov270_CreateNamedEntity(int);

void Ov270_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x5c, Ov270_CreateNamedEntity);
}
