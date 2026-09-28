/* Registers Ov301_CreateNamedEntity as the factory for entity class 0x75. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov301_CreateNamedEntity(int);

void Ov301_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x75, Ov301_CreateNamedEntity);
}
