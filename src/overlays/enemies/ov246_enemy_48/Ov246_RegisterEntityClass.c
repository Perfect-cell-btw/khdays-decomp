/* Register the ov246 object factory (type 0x48) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov246_CreateNamedEntity(int);
int Ov246_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x48, (void *)&Ov246_CreateNamedEntity);
}
