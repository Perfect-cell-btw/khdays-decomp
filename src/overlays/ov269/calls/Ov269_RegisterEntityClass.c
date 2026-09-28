extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov269_CreateNamedEntity(int);

void Ov269_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x5c, Ov269_CreateNamedEntity);
}
