/* Register the ov211 object factory (type 0x2b) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov211_CreateNamedEntity(int);
int Ov211_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x2b, (void *)&Ov211_CreateNamedEntity);
}
