/* Registers Ov161_CreateNamedEntity as the factory for entity class 0x18. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov161_CreateNamedEntity(int);

void Ov161_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x18, Ov161_CreateNamedEntity);
}
