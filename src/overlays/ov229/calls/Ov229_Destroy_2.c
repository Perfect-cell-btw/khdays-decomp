extern int DestroyInstance();
extern int Ov107_DestroyObject();

int Ov229_Destroy_2(int *r0) {
    DestroyInstance(r0[0x384 / 4]);
    DestroyInstance(r0[0x390 / 4]);
    return Ov107_DestroyObject(r0);
}
