/* Registers Ov144_CreateNamedEntity as the factory for entity class 0xe. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov144_CreateNamedEntity(int);

void Ov144_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0e, Ov144_CreateNamedEntity);
}
