/* Register the ov237 object factory (type 0x40) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov237_CreateNamedEntity(int);
int Ov237_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x40, (void *)&Ov237_CreateNamedEntity);
}
