/* Register the ov278 object factory (type 0x63) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov278_CreateNamedEntity(int);
int Ov278_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x63, (void *)&Ov278_CreateNamedEntity);
}
