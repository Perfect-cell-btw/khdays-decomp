/* Register the ov249 object factory (type 0x4a) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov249_CreateNamedEntity(int);
int Ov249_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x4a, (void *)&Ov249_CreateNamedEntity);
}
