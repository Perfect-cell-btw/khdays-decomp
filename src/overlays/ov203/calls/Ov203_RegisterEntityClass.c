extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov203_AllocActorWithName(int);

void Ov203_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x27, Ov203_AllocActorWithName);
}
