/* Allocate a 0x39c-byte object, link it back to this owner (+0x38c),
 * install the 020cf864 callback (+0x18c), init via 020c6624 and return it. */
extern int CallocInstance(int a);
extern void func_ov107_020c6624(int a, int b);
extern void Ov125_ConstructSubitem(int);
int Ov125_Actor_New(int param_1) {
    int obj = CallocInstance(0x39c);
    *(int *)(obj + 0x38c) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov125_ConstructSubitem;
    func_ov107_020c6624(obj, 0);
    return obj;
}
