extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov289_CreateNamedEntity(int);

void Ov289_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6b, Ov289_CreateNamedEntity);
}
