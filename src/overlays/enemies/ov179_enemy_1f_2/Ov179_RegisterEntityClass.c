/* Registers Ov179_CreateNamedEntity as the factory for entity class 0x1f. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov179_CreateNamedEntity(int);

void Ov179_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1f, Ov179_CreateNamedEntity);
}
