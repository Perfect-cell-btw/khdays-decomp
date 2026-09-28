/* Register the ov228 object factory (type 0x39) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov228_CreateNamedEntity(int);
int Ov228_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x39, (void *)&Ov228_CreateNamedEntity);
}
