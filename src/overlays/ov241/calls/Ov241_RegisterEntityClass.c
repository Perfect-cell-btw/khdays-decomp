extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov241_CreateNamedEntity(int);

void Ov241_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x44, Ov241_CreateNamedEntity);
}
