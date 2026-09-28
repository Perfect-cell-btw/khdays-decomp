extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov284_CreateNamedEntity(int);

void Ov284_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x69, Ov284_CreateNamedEntity);
}
