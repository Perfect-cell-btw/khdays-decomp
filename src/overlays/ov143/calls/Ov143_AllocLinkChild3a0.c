extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov143_InitializeSubObject();

int Ov143_AllocLinkChild3a0(int this_) {
    int obj = CallocInstance(0x3a0);
    *(int *)(obj + 0x398) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov143_InitializeSubObject;
    func_ov107_020c6624(obj, 0, (int)&Ov143_InitializeSubObject);
    return obj;
}
