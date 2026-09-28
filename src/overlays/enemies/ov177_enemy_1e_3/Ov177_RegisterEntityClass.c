/* Registers Ov177_CreateNamedEntity as the factory for entity class 0x1e. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov177_CreateNamedEntity(int);

void Ov177_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x1e, Ov177_CreateNamedEntity);
}
