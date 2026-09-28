/* Registers Ov288_CreateNamedEntity as the factory for entity class 0x6b. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov288_CreateNamedEntity(int);

void Ov288_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x6b, Ov288_CreateNamedEntity);
}
