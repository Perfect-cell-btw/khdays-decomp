/* Registers Ov196_CreateNamedEntity as the factory for entity class 0x24. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov196_CreateNamedEntity(int);

void Ov196_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x24, Ov196_CreateNamedEntity);
}
