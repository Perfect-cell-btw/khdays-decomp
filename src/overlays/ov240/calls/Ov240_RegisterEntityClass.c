extern void Ov107_RegisterHandler(int arg0, void (*arg1)(int));
extern void Ov240_CreateNamedEntity(int);

void Ov240_RegisterEntityClass(void) {
    Ov107_RegisterHandler(0x43, Ov240_CreateNamedEntity);
}
