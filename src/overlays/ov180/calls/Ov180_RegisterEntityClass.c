extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov180_CreateNamedEntity(int);

void Ov180_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1f, Ov180_CreateNamedEntity);
}
