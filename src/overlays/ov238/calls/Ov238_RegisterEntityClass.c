/* Register the ov238 object factory (type 0x41) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov238_CreateNamedEntity(int);
int Ov238_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x41, (void *)&Ov238_CreateNamedEntity);
}
