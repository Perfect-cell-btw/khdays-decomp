/* Registers Ov286_CreateNamedEntity as the factory for entity class 0x6a. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov286_CreateNamedEntity(int);

void Ov286_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6a, Ov286_CreateNamedEntity);
}
