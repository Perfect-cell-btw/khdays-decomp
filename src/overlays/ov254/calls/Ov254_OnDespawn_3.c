extern int DestroyInstance();
extern int Ov107_DestroyObject();

int Ov254_OnDespawn_3(int *r0) {
    DestroyInstance(((int *)r0)[0x384 / 4]);
    return Ov107_DestroyObject(r0);
}
