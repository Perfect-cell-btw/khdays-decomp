extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov114_CreateNamedEntity(int);

void Ov114_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x00, Ov114_CreateNamedEntity);
}
