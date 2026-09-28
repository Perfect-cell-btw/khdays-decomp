extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov262_CreateNamedEntity(int);

void Ov262_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x55, Ov262_CreateNamedEntity);
}
