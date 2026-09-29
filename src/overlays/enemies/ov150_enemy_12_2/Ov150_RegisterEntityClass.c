/* Registers Ov150_CreateNamedEntity as the factory for entity class 0x12. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov150_CreateNamedEntity(int);

void Ov150_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x12, Ov150_CreateNamedEntity);
}
