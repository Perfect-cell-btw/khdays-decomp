/* Registers Ov118_CreateNamedEntity as the factory for entity class 0x2. */

extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov118_CreateNamedEntity(int);

void Ov118_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x02, Ov118_CreateNamedEntity);
}
