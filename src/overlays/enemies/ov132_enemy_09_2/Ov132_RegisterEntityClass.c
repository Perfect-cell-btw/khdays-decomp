/* Registers Ov132_CreateNamedEntity as the factory for entity class 0x9. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov132_CreateNamedEntity(int);

void Ov132_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x09, Ov132_CreateNamedEntity);
}
