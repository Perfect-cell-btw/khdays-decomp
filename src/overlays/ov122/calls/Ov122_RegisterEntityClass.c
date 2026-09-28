/* Registers Ov122_CreateNamedEntity as the factory for entity class 0x4. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov122_CreateNamedEntity(int);

void Ov122_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x04, Ov122_CreateNamedEntity);
}
