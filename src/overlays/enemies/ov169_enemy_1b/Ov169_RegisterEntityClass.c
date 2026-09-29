/* Registers Ov169_CreateNamedEntity as the factory for entity class 0x1b. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov169_CreateNamedEntity(int);

void Ov169_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1b, Ov169_CreateNamedEntity);
}
