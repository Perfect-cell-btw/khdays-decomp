extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov150_CreateNamedEntity(int);

void Ov150_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x12, Ov150_CreateNamedEntity);
}
