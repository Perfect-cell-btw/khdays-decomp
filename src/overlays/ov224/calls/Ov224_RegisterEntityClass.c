/* Register the ov224 object factory (type 0x35) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov224_CreateNamedEntity(int);
int Ov224_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x35, (void *)&Ov224_CreateNamedEntity);
}
