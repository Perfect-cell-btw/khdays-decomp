/* Registers Ov129_CreateNamedEntity as the factory for entity class 0x7. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov129_CreateNamedEntity(int);

void Ov129_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x07, Ov129_CreateNamedEntity);
}
