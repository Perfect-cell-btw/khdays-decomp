extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov148_CreateNamedEntity(int);

void Ov148_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x11, Ov148_CreateNamedEntity);
}
