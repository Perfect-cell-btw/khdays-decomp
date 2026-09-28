extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov127_CreateNamedEntity(int);

void Ov127_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x07, Ov127_CreateNamedEntity);
}
