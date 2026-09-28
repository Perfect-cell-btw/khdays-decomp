/* Registers Ov114_CreateNamedEntity as the factory for entity class 0x0. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov114_CreateNamedEntity(int);

void Ov114_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x00, Ov114_CreateNamedEntity);
}
