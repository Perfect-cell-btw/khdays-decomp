/* Register the ov255 object factory (type 0x4f) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov255_CreateNamedEntity(int);
int Ov255_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x4f, (void *)&Ov255_CreateNamedEntity);
}
