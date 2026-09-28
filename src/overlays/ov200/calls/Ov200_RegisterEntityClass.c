/* Register the ov200 object factory (type 0x26) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov200_CreateNamedEntity(int);
int Ov200_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x26, (void *)&Ov200_CreateNamedEntity);
}
