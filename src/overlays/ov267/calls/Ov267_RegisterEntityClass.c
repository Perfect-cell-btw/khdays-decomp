/* Register the ov267 object factory (type 0x5a) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov267_CreateNamedEntity(int);
int Ov267_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x5a, (void *)&Ov267_CreateNamedEntity);
}
