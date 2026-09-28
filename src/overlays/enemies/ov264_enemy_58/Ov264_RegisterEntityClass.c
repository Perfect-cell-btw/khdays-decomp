/* Registers Ov264_AllocActorWithName as the factory for entity class 0x58. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov264_AllocActorWithName(int);

void Ov264_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x58, Ov264_AllocActorWithName);
}
