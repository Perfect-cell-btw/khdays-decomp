extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov156_CreateNamedEntity(int);

void Ov156_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x15, Ov156_CreateNamedEntity);
}
