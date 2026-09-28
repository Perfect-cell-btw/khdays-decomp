extern int Ov107_RegisterHandler(int, void *);
extern int Ov125_CreateNamedEntity(int);
int Ov125_RegisterEntityClass(void) {
    return Ov107_RegisterHandler(0x6, (void *)&Ov125_CreateNamedEntity);
}
