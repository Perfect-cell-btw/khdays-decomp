/* Register the ov230 object factory (type 0x3a) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov230_CreateNamedEntity(int);
int Ov230_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3a, (void *)&Ov230_CreateNamedEntity);
}
