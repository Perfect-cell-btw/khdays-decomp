extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov251_CreateNamedEntity(int);

void Ov251_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x4b, Ov251_CreateNamedEntity);
}
