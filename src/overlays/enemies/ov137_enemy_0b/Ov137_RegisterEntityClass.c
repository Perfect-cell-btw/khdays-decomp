/* Register the ov137 object factory (type 0xb) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov137_CreateNamedEntity(int);
int Ov137_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0xb, (void *)&Ov137_CreateNamedEntity);
}
