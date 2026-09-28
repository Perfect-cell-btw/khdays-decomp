/* Registers Ov128_CreateNamedEntity as the factory for entity class 0x7. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov128_CreateNamedEntity(int);

void Ov128_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x07, Ov128_CreateNamedEntity);
}
