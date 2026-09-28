extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov242_CreateNamedEntity(int);

void Ov242_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x44, Ov242_CreateNamedEntity);
}
