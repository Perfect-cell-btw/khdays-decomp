/* Register the ov222 object factory (type 0x33) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov222_CreateNamedEntity(int);
int Ov222_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x33, (void *)&Ov222_CreateNamedEntity);
}
