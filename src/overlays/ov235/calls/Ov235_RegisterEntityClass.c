/* Register the ov235 object factory (type 0x3e) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov235_CreateNamedEntity(int);
int Ov235_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3e, (void *)&Ov235_CreateNamedEntity);
}
