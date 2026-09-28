/* Register the ov274 object factory (type 0x60) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov274_CreateNamedEntity(int);
int Ov274_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x60, (void *)&Ov274_CreateNamedEntity);
}
