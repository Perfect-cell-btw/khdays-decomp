/* Registers Ov204_CreateNamedEntity as the factory for entity class 0x28. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov204_CreateNamedEntity(int);

void Ov204_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x28, Ov204_CreateNamedEntity);
}
