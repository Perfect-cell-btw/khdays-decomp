/* Register the ov259 object factory (type 0x53) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov259_CreateNamedEntity(int);
int Ov259_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x53, (void *)&Ov259_CreateNamedEntity);
}
