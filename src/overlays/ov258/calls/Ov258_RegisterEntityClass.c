/* Register the ov258 object factory (type 0x52) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov258_CreateNamedEntity(int);
int Ov258_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x52, (void *)&Ov258_CreateNamedEntity);
}
