/* Register the ov283 object factory (type 0x68) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov283_CreateNamedEntity(int);
int Ov283_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x68, (void *)&Ov283_CreateNamedEntity);
}
