/* Registers Ov115_CreateNamedEntity as the factory for entity class 0x1. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov115_CreateNamedEntity(int);

void Ov115_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x01, Ov115_CreateNamedEntity);
}
