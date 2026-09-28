/* Register the ov252 object factory (type 0x4c) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov252_CreateNamedEntity(int);
int Ov252_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x4c, (void *)&Ov252_CreateNamedEntity);
}
