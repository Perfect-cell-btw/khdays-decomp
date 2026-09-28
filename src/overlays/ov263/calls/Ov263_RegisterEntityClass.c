/* Register the ov263 object factory (type 0x57) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov263_CreateNamedEntity(int);
int Ov263_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x57, (void *)&Ov263_CreateNamedEntity);
}
