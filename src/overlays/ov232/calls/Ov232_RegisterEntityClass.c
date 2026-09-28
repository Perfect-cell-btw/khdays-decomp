/* Register the ov232 object factory (type 0x3b) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov232_CreateNamedEntity(int);
int Ov232_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x3b, (void *)&Ov232_CreateNamedEntity);
}
