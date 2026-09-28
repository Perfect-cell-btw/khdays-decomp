/* Allocate the 0x398-byte sub-actor, back-link the owner at +0x38c, install its update
 * handler at +0x18c, run the ov107 setup and return it. */
extern int CallocInstance(int size);
extern void func_ov107_020c6624(int a, int b);
extern void Ov254_HelperDConstruct(void);
int Ov254_HelperD_New(int param_1) {
    int obj = CallocInstance(0x398);
    *(int *)(obj + 0x38c) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov254_HelperDConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
