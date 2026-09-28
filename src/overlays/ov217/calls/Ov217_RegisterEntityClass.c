extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov217_AllocActorWithName(int);

void Ov217_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x2f, Ov217_AllocActorWithName);
}
