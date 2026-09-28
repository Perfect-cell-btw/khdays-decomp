/* Register the ov233 object factory (type 0x3c) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov233_CreateNamedEntity(int);
int Ov233_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3c, (void *)&Ov233_CreateNamedEntity);
}
