/* Registers Ov142_CreateNamedEntity as the factory for entity class 0xd. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov142_CreateNamedEntity(int);

void Ov142_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x0d, Ov142_CreateNamedEntity);
}
