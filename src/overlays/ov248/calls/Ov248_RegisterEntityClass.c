/* Register the ov248 object factory (type 0x49) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov248_CreateNamedEntity(int);
int Ov248_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x49, (void *)&Ov248_CreateNamedEntity);
}
