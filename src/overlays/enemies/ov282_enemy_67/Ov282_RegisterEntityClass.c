/* Register the ov282 object factory (type 0x67) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov282_CreateNamedEntity(int);
int Ov282_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x67, (void *)&Ov282_CreateNamedEntity);
}
