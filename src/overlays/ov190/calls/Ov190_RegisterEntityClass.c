/* Registers Ov190_CreateNamedEntity as the factory for entity class 0x22. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov190_CreateNamedEntity(int);

void Ov190_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x22, Ov190_CreateNamedEntity);
}
