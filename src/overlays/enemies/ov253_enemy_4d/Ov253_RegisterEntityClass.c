/* Register the ov253 object factory (type 0x4d) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov253_CreateNamedEntity(int);
int Ov253_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x4d, (void *)&Ov253_CreateNamedEntity);
}
