/* Registers Ov135_CreateNamedEntity as the factory for entity class 0xa. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov135_CreateNamedEntity(int);

void Ov135_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0a, Ov135_CreateNamedEntity);
}
