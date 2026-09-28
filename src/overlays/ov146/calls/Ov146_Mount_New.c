/* Allocate a 0x394-byte object, link it back to this owner (+0x388),
 * install the 020cee64 callback (+0x18c), init via 020c6624 and return it. */
extern int CallocInstance(int a);
extern void func_ov107_020c6624(int a, int b);
extern void Ov146_Setup(int);
int Ov146_Mount_New(int param_1) {
    int obj = CallocInstance(0x394);
    *(int *)(obj + 0x388) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov146_Setup;
    func_ov107_020c6624(obj, 0);
    return obj;
}
