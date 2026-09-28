extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov141_CreateNamedEntity(int);

void Ov141_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, Ov141_CreateNamedEntity);
}
