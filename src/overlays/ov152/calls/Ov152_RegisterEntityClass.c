/* Registers Ov152_CreateNamedEntity as the factory for entity class 0x13. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov152_CreateNamedEntity(int);

void Ov152_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x13, Ov152_CreateNamedEntity);
}
