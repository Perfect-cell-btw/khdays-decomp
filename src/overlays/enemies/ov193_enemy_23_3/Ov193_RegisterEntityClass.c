/* Registers Ov193_CreateNamedEntity as the factory for entity class 0x23. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov193_CreateNamedEntity(int);

void Ov193_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x23, Ov193_CreateNamedEntity);
}
