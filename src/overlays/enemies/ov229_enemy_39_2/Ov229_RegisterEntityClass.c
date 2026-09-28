/* Register the ov229 object factory (type 0x39) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov229_CreateNamedEntity(int);
int Ov229_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x39, (void *)&Ov229_CreateNamedEntity);
}
