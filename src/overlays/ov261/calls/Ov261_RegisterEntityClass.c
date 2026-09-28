/* Registers Ov261_CreateNamedEntity as the factory for entity class 0x55. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov261_CreateNamedEntity(int);

void Ov261_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x55, Ov261_CreateNamedEntity);
}
