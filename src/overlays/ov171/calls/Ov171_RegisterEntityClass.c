/* Registers Ov171_CreateNamedEntity as the factory for entity class 0x1c. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov171_CreateNamedEntity(int);

void Ov171_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1c, Ov171_CreateNamedEntity);
}
