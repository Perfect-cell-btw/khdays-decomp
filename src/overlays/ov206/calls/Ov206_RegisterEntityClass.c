/* Register the ov206 object factory (type 0x29) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov206_CreateNamedEntity(int);
int Ov206_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x29, (void *)&Ov206_CreateNamedEntity);
}
