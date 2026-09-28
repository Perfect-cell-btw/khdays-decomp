extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov147_CreateNamedEntity(int);

void Ov147_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x11, Ov147_CreateNamedEntity);
}
