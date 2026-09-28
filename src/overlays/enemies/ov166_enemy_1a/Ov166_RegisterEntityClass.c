/* Registers Ov166_CreateNamedEntity as the factory for entity class 0x1a. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov166_CreateNamedEntity(int);

void Ov166_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1a, Ov166_CreateNamedEntity);
}
