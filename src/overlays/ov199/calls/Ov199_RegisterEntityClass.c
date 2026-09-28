/* Register the ov199 object factory (type 0x25) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov199_CreateNamedEntity(int);
int Ov199_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x25, (void *)&Ov199_CreateNamedEntity);
}
