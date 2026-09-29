/* Registers Ov124_CreateNamedEntity as the factory for entity class 0x5. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov124_CreateNamedEntity(int);

void Ov124_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x05, Ov124_CreateNamedEntity);
}
