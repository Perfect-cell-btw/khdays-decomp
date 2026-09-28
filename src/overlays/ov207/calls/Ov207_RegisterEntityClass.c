/* Register the ov207 object factory (type 0x29) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov207_CreateNamedEntity(int);
int Ov207_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x29, (void *)&Ov207_CreateNamedEntity);
}
