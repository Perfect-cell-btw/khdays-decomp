/* Register the ov210 object factory (type 0x2b) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov210_CreateNamedEntity(int);
int Ov210_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x2b, (void *)&Ov210_CreateNamedEntity);
}
