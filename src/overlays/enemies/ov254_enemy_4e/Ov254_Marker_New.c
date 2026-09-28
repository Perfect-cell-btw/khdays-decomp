/* Allocate a 0x38c-byte object, link it back to this owner (+0x388),
 * install the 020d4da0 callback (+0x18c), init via 020c6624 and return it. */
extern int CallocInstance(int a);
extern void func_ov107_020c6624(int a, int b);
extern void Ov254_MarkerConstruct(int);
int Ov254_Marker_New(int param_1) {
    int obj = CallocInstance(0x38c);
    *(int *)(obj + 0x388) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov254_MarkerConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
