/* Registers Ov285_CreateNamedEntity as the factory for entity class 0x6a. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov285_CreateNamedEntity(int);

void Ov285_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6a, Ov285_CreateNamedEntity);
}
