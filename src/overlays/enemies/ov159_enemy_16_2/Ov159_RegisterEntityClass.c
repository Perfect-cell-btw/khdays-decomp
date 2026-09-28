/* Register the ov159 object factory (type 0x16) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov159_CreateNamedEntity(int);
int Ov159_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x16, (void *)&Ov159_CreateNamedEntity);
}
