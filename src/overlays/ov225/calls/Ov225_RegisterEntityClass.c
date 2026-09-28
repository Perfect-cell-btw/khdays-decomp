/* Register the ov225 object factory (type 0x36) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov225_CreateNamedEntity(int);
int Ov225_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x36, (void *)&Ov225_CreateNamedEntity);
}
