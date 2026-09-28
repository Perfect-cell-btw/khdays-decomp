/* Register the ov277 object factory (type 0x62) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov277_CreateNamedEntity_2(int);
int Ov277_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x62, (void *)&Ov277_CreateNamedEntity_2);
}
