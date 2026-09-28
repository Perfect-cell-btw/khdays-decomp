/* Register the ov236 object factory (type 0x3f) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov236_CreateNamedEntity(int);
int Ov236_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3f, (void *)&Ov236_CreateNamedEntity);
}
