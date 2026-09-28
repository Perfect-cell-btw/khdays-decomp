/* Register the ov266 object factory (type 0x5a) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov266_CreateNamedEntity(int);
int Ov266_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x5a, (void *)&Ov266_CreateNamedEntity);
}
