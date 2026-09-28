extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov142_CreateNamedEntity(int);

void Ov142_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, Ov142_CreateNamedEntity);
}
