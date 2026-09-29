/* Registers Ov145_CreateNamedEntity as the factory for entity class 0xf. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov145_CreateNamedEntity(int);

void Ov145_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0f, Ov145_CreateNamedEntity);
}
