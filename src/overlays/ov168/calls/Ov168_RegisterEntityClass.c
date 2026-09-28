extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov168_CreateNamedEntity(int);

void Ov168_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1a, Ov168_CreateNamedEntity);
}
