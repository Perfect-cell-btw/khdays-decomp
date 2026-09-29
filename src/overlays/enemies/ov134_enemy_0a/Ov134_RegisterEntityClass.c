/* Registers Ov134_CreateNamedEntity as the factory for entity class 0xa. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov134_CreateNamedEntity(int);

void Ov134_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0a, Ov134_CreateNamedEntity);
}
