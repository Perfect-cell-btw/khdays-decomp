/* Register the ov273 object factory (type 0x5f) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov273_CreateNamedEntity(int);
int Ov273_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x5f, (void *)&Ov273_CreateNamedEntity);
}
