/* Registers Ov147_CreateNamedEntity as the factory for entity class 0x11. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov147_CreateNamedEntity(int);

void Ov147_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x11, Ov147_CreateNamedEntity);
}
