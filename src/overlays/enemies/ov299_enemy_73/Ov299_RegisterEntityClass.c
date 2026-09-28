/* Registers Ov299_CreateNamedEntity as the factory for entity class 0x73. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov299_CreateNamedEntity(int);

void Ov299_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x73, Ov299_CreateNamedEntity);
}
