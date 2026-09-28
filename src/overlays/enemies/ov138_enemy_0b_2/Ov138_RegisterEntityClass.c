/* Register the ov138 object factory (type 0xb) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov138_CreateNamedEntity(int);
int Ov138_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0xb, (void *)&Ov138_CreateNamedEntity);
}
