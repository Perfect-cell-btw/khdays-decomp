/* Registers Ov287_CreateNamedEntity as the factory for entity class 0x6b. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov287_CreateNamedEntity(int);

void Ov287_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6b, Ov287_CreateNamedEntity);
}
