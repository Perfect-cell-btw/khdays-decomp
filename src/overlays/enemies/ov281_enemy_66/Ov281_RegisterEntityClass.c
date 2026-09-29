/* Registers Ov281_CreateNamedEntity as the factory for entity class 0x66. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov281_CreateNamedEntity(int);

void Ov281_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x66, Ov281_CreateNamedEntity);
}
