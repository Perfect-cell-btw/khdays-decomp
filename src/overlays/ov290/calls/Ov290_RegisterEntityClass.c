extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov290_CreateNamedEntity(int);

void Ov290_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6c, Ov290_CreateNamedEntity);
}
