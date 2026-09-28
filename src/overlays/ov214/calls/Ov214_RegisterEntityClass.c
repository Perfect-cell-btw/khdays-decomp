extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov214_AllocActorWithName(int);

void Ov214_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2e, Ov214_AllocActorWithName);
}
