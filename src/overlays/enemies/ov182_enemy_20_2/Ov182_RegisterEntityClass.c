/* Registers Ov182_CreateNamedEntity as the factory for entity class 0x20. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov182_CreateNamedEntity(int);

void Ov182_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x20, Ov182_CreateNamedEntity);
}
