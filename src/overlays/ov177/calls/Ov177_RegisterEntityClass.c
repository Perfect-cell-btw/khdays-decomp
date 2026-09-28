extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov177_CreateNamedEntity(int);

void Ov177_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1e, Ov177_CreateNamedEntity);
}
