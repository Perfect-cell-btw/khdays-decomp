/* Registers Ov194_CreateNamedEntity as the factory for entity class 0x24. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov194_CreateNamedEntity(int);

void Ov194_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x24, Ov194_CreateNamedEntity);
}
