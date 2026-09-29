/* Registers Ov154_CreateNamedEntity as the factory for entity class 0x14. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov154_CreateNamedEntity(int);

void Ov154_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x14, Ov154_CreateNamedEntity);
}
