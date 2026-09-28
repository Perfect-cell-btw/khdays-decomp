extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov172_CreateNamedEntity(int);

void Ov172_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1c, Ov172_CreateNamedEntity);
}
