/* Registers Ov297_CreateNamedEntity as the factory for entity class 0x71. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov297_CreateNamedEntity(int);

void Ov297_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x71, Ov297_CreateNamedEntity);
}
