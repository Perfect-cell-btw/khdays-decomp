/* Register the ov279 object factory (type 0x64) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov279_CreateNamedEntity(int);
int Ov279_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x64, (void *)&Ov279_CreateNamedEntity);
}
