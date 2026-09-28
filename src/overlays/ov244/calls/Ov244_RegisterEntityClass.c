/* Register the ov244 object factory (type 0x46) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov244_CreateNamedEntity_2(int);
int Ov244_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x46, (void *)&Ov244_CreateNamedEntity_2);
}
