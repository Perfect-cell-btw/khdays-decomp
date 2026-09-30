/* Allocate a 0x410-byte object, link it back to this owner (+0x394), install the ov208_020d3768
 * callback (+0x18c), initialise it via ov107_020c6624 and return it. */
extern int CallocInstance(int a);
extern void func_ov107_020c6624(int a, int b);
extern void Ov209_ItemConstruct(int);
int Ov209_New(int param_1) {
    int obj = CallocInstance(0x410);
    *(int *)(obj + 0x394) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov209_ItemConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
