/* Register the ov231 object factory (type 0x3b) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov231_CreateNamedEntity(int);
int Ov231_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3b, (void *)&Ov231_CreateNamedEntity);
}
