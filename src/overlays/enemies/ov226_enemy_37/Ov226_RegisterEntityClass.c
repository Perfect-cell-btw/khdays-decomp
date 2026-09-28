/* Register the ov226 object factory (type 0x37) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov226_CreateNamedEntity(int);
int Ov226_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x37, (void *)&Ov226_CreateNamedEntity);
}
