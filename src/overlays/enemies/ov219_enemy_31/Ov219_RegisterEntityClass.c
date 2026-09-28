/* Registers Ov219_CreateNamedEntity as the factory for entity class 0x31. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov219_CreateNamedEntity(int);

void Ov219_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x31, Ov219_CreateNamedEntity);
}
