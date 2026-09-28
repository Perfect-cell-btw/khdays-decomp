/* Dispatch to Ov107_RegisterHandler with code 0x21 and handler Ov186_CreateNamedEntity_2. */
extern int Ov107_RegisterHandler(int a, void *handler);
extern void Ov186_CreateNamedEntity_2(void);
int Ov186_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x21, (void *)&Ov186_CreateNamedEntity_2);
}
