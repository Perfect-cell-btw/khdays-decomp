/* Allocate a 0x1ec-byte object, initialise it (with this owner) via ov107_020cac24 and return it. */
extern int CallocInstance(int a);
extern void Ov107_Pillar_Init(int a, int b);
int Ov107_Pillar_New(int param_1) {
    int obj = CallocInstance(0x1ec);
    Ov107_Pillar_Init(obj, param_1);
    return obj;
}
