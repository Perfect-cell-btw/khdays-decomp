/* Registers Ov292_CreateNamedEntity as the factory for entity class 0x6e. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov292_CreateNamedEntity(int);

void Ov292_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6e, Ov292_CreateNamedEntity);
}
