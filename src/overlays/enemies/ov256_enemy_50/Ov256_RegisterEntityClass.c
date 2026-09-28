/* Register the ov256 object factory (type 0x50) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov256_CreateNamedEntity(int);
int Ov256_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x50, (void *)&Ov256_CreateNamedEntity);
}
