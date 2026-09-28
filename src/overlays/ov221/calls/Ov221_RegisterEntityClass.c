/* Register the ov221 object factory (type 0x33) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov221_CreateNamedEntity(int);
int Ov221_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x33, (void *)&Ov221_CreateNamedEntity);
}
