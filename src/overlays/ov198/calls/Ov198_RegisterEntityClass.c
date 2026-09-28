extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov198_CreateNamedEntity(int);

void Ov198_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x25, Ov198_CreateNamedEntity);
}
