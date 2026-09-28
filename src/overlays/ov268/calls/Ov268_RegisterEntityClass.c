/* Register the ov268 object factory (type 0x5b) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov268_CreateNamedEntity(int);
int Ov268_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x5b, (void *)&Ov268_CreateNamedEntity);
}
