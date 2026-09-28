/* Register the ov245 object factory (type 0x47) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov245_CreateNamedEntity(int);
int Ov245_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x47, (void *)&Ov245_CreateNamedEntity);
}
