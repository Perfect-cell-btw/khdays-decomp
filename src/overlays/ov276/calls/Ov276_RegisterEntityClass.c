extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov276_AllocActorWithName(int);

void Ov276_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x61, Ov276_AllocActorWithName);
}
