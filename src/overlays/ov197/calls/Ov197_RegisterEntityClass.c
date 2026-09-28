/* Registers Ov197_CreateNamedEntity as the factory for entity class 0x25. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov197_CreateNamedEntity(int);

void Ov197_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x25, Ov197_CreateNamedEntity);
}
