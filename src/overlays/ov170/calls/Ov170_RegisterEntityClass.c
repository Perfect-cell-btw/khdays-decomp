extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov170_CreateNamedEntity(int);

void Ov170_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1b, Ov170_CreateNamedEntity);
}
