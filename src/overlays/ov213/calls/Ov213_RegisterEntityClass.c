/* Register the ov213 object factory (type 0x2d) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov213_CreateNamedEntity(int);
int Ov213_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x2d, (void *)&Ov213_CreateNamedEntity);
}
