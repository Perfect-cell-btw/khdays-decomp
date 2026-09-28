extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov174_CreateNamedEntity(int);

void Ov174_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1d, Ov174_CreateNamedEntity);
}
