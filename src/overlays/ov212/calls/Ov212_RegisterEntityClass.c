/* Register the ov212 object factory (type 0x2c) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov212_CreateNamedEntity(int);
int Ov212_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x2c, (void *)&Ov212_CreateNamedEntity);
}
