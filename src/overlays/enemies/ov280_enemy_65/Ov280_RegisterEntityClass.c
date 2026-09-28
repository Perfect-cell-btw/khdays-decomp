/* Register the ov280 object factory (type 0x65) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov280_CreateNamedEntity(int);
int Ov280_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x65, (void *)&Ov280_CreateNamedEntity);
}
