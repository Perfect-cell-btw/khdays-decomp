/* Register the ov146 object factory (type 0x10) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov146_CreateNamedEntity(int);
int Ov146_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x10, (void *)&Ov146_CreateNamedEntity);
}
