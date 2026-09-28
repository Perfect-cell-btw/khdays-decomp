/* Allocate a 0x3c8-byte object, link it back to this owner (+0x3b4),
 * install the 020d3838 callback (+0x18c), init via 020c6624 and return it. */
extern int CallocInstance(int a);
extern void func_ov107_020c6624(int a, int b);
extern void Ov245_FourShapeConstruct(int);
int Ov245_FourShape_New(int param_1) {
    int obj = CallocInstance(0x3c8);
    *(int *)(obj + 0x3b4) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov245_FourShapeConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
