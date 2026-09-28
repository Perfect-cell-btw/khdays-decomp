/* Dispatch to Ov107_RegisterHandler with code 0x21 and handler Ov187_CreateNamedEntity_2. */
extern int Ov107_RegisterHandler(int a, void *handler);
extern void Ov187_CreateNamedEntity_2(void);
int Ov187_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x21, (void *)&Ov187_CreateNamedEntity_2);
}
