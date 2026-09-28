/* Register the ov119 object factory (type 0x3) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov119_CreateNamedEntity(int);
int Ov119_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3, (void *)&Ov119_CreateNamedEntity);
}
