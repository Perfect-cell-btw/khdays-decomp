/* Register the ov247 object factory (type 0x48) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov247_CreateNamedEntity(int);
int Ov247_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x48, (void *)&Ov247_CreateNamedEntity);
}
