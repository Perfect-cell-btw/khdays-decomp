/* Register the ov160 object factory (type 0x17) with the shared registrar. */
extern int Ov107_RegisterHandler(int, void *);
extern int Ov160_CreateNamedEntity(int);
int Ov160_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x17, (void *)&Ov160_CreateNamedEntity);
}
