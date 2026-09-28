extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov300_CreateNamedEntity(int);

void Ov300_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x74, Ov300_CreateNamedEntity);
}
