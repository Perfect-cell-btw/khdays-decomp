/* Register the ov254 object factory (type 0x4e) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov254_CreateNamedEntity(int);
int Ov254_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x4e, (void *)&Ov254_CreateNamedEntity);
}
