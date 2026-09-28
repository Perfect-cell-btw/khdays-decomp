/* Registers Ov165_CreateNamedEntity as the factory for entity class 0x19. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov165_CreateNamedEntity(int);

void Ov165_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x19, Ov165_CreateNamedEntity);
}
