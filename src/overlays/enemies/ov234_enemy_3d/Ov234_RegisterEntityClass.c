/* Registers Ov234_CreateNamedEntity as the factory for entity class 0x3d. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov234_CreateNamedEntity(int);

void Ov234_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x3d, Ov234_CreateNamedEntity);
}
