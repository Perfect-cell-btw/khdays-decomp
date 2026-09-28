extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov192_CreateNamedEntity(int);

void Ov192_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x23, Ov192_CreateNamedEntity);
}
