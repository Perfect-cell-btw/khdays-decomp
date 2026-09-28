/* Register the ov227 object factory (type 0x38) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov227_CreateNamedEntity(int);
int Ov227_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x38, (void *)&Ov227_CreateNamedEntity);
}
