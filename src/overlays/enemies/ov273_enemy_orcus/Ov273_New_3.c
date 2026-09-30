/* Allocate a 0x39c-byte object, link it back to this owner (+0x384),
 * install the 020d6000 callback (+0x18c), init via 020c6624 and return it. */
extern int CallocInstance(int a);
extern void func_ov107_020c6624(int a, int b);
extern void Ov273_Construct_2(int);
int Ov273_New_3(int param_1) {
    int obj = CallocInstance(0x39c);
    *(int *)(obj + 0x384) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov273_Construct_2;
    func_ov107_020c6624(obj, 0);
    return obj;
}
