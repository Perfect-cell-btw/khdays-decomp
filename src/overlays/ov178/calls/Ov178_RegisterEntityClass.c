extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov178_CreateNamedEntity(int);

void Ov178_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1f, Ov178_CreateNamedEntity);
}
