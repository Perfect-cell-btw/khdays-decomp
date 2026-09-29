/* Registers Ov220_CreateNamedEntity as the factory for entity class 0x32. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov220_CreateNamedEntity(int);

void Ov220_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x32, Ov220_CreateNamedEntity);
}
