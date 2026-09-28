/* Register the ov201 object factory (type 0x26) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov201_CreateNamedEntity(int);
int Ov201_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x26, (void *)&Ov201_CreateNamedEntity);
}
