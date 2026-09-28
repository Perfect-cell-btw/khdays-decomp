/* Register the ov275 object factory (type 0x60) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov275_CreateNamedEntity(int);
int Ov275_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x60, (void *)&Ov275_CreateNamedEntity);
}
