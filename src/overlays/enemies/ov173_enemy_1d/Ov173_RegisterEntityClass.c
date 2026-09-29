/* Registers Ov173_CreateNamedEntity as the factory for entity class 0x1d. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov173_CreateNamedEntity(int);

void Ov173_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1d, Ov173_CreateNamedEntity);
}
