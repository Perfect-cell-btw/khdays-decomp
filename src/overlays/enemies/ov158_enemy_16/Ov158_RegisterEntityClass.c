/* Register the ov158 object factory (type 0x16) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov158_CreateNamedEntity(int);
int Ov158_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x16, (void *)&Ov158_CreateNamedEntity);
}
