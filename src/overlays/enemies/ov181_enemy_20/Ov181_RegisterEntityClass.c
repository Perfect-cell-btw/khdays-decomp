/* Registers Ov181_CreateNamedEntity as the factory for entity class 0x20. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov181_CreateNamedEntity(int);

void Ov181_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, Ov181_CreateNamedEntity);
}
