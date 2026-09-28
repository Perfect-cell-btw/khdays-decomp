extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov152_CreateNamedEntity(int);

void Ov152_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x13, Ov152_CreateNamedEntity);
}
