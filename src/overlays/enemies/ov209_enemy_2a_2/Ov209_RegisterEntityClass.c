/* Register the ov209 object factory (type 0x2a) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov209_CreateNamedEntity(int);
int Ov209_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x2a, (void *)&Ov209_CreateNamedEntity);
}
