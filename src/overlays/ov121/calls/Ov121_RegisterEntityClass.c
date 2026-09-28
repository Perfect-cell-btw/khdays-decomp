extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov121_CreateNamedEntity(int);

void Ov121_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, Ov121_CreateNamedEntity);
}
