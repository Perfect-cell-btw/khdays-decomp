/* Registers Ov191_CreateNamedEntity as the factory for entity class 0x23. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov191_CreateNamedEntity(int);

void Ov191_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x23, Ov191_CreateNamedEntity);
}
