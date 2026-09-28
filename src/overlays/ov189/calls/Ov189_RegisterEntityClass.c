/* Registers Ov189_CreateNamedEntity as the factory for entity class 0x22. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov189_CreateNamedEntity(int);

void Ov189_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x22, Ov189_CreateNamedEntity);
}
