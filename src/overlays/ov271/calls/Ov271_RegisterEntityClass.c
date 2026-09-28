/* Register the ov271 object factory (type 0x5d) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov271_CreateNamedEntity(int);
int Ov271_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x5d, (void *)&Ov271_CreateNamedEntity);
}
