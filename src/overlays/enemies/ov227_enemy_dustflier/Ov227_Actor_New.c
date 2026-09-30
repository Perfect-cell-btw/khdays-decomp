/* Allocate a 0x3a0-byte object, wire its owner (+0x38c) and vtable/handler
 * (+0x18c = Ov227_PartConstruct), start it via func_ov107_020c6624, and return it. */
extern int CallocInstance(int size);
extern void func_ov107_020c6624(int a, int b);
extern void Ov227_PartConstruct(void);
int Ov227_Actor_New(int param_1) {
    int obj = CallocInstance(0x3a0);
    *(int *)(obj + 0x38c) = param_1;
    *(int *)(obj + 0x18c) = (int)&Ov227_PartConstruct;
    func_ov107_020c6624(obj, 0);
    return obj;
}
