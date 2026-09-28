/* Register the ov260 object factory (type 0x54) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov260_CreateNamedEntity(int);
int Ov260_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x54, (void *)&Ov260_CreateNamedEntity);
}
