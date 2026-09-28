/* Register the ov272 object factory (type 0x5e) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov272_CreateNamedEntity(int);
int Ov272_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x5e, (void *)&Ov272_CreateNamedEntity);
}
