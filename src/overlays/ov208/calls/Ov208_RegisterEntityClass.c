/* Register the ov208 object factory (type 0x2a) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov208_CreateNamedEntity(int);
int Ov208_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x2a, (void *)&Ov208_CreateNamedEntity);
}
