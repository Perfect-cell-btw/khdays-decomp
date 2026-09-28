/* Registers Ov183_CreateNamedEntity as the factory for entity class 0x20. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov183_CreateNamedEntity(int);

void Ov183_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, Ov183_CreateNamedEntity);
}
