/* Registers Ov188_CreateNamedEntity as the factory for entity class 0x22. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov188_CreateNamedEntity(int);

void Ov188_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x22, Ov188_CreateNamedEntity);
}
