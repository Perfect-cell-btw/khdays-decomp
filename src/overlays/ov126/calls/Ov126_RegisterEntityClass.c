/* Register the ov126 object factory (type 0x6) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov126_CreateNamedEntity(int);
int Ov126_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x6, (void *)&Ov126_CreateNamedEntity);
}
