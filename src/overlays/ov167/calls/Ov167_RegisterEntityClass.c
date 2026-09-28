extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov167_CreateNamedEntity(int);

void Ov167_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1a, Ov167_CreateNamedEntity);
}
