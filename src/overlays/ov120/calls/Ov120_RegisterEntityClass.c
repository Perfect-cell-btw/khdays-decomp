/* Registers Ov120_CreateNamedEntity as the factory for entity class 0x4. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov120_CreateNamedEntity(int);

void Ov120_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, Ov120_CreateNamedEntity);
}
