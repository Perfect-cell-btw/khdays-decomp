/* Register the ov218 object factory (type 0x30) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov218_CreateNamedEntity(int);
int Ov218_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x30, (void *)&Ov218_CreateNamedEntity);
}
