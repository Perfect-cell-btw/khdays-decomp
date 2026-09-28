/* Registers Ov123_CreateNamedEntity as the factory for entity class 0x5. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov123_CreateNamedEntity(int);

void Ov123_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x05, Ov123_CreateNamedEntity);
}
