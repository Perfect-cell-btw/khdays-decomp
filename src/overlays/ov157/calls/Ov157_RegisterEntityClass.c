extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov157_CreateNamedEntity(int);

void Ov157_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x15, Ov157_CreateNamedEntity);
}
