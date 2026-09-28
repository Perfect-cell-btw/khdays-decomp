/* Allocate the 0x39c-byte sub-actor, back-link the owner at +0x388, install its update
 * handler at +0x18c, run the ov107 setup and return it. */
extern int CallocInstance(int size);
extern void func_ov107_020c6624(int a, int b);
extern void Ov232_ItemConstruct(void);
int Ov232_Item_New(int param_1) {
    int obj = CallocInstance(0x39c);
    *(int *)(obj + 0x388) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov232_ItemConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
