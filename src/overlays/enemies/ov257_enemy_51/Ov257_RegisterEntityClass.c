/* Register the ov257 object factory (type 0x51) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov257_CreateNamedEntity(int);
int Ov257_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x51, (void *)&Ov257_CreateNamedEntity);
}
