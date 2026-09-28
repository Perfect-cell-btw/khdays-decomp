/* Register the ov265 object factory (type 0x59) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov265_CreateNamedEntity(int);
int Ov265_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x59, (void *)&Ov265_CreateNamedEntity);
}
