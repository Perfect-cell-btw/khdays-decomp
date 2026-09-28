/* Register the ov223 object factory (type 0x34) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov223_CreateNamedEntity(int);
int Ov223_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x34, (void *)&Ov223_CreateNamedEntity);
}
