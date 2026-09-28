extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov136_CreateNamedEntity(int);

void Ov136_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0a, Ov136_CreateNamedEntity);
}
