/* Registers Ov216_AllocActorWithName as the factory for entity class 0x2f. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov216_AllocActorWithName(int);

void Ov216_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2f, Ov216_AllocActorWithName);
}
