extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov155_CreateNamedEntity(int);

void Ov155_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x14, Ov155_CreateNamedEntity);
}
