extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov198_InitSubActor();

int Ov198_AllocLinkChild3a4(int this_) {
    int obj = CallocInstance(0x3a4);
    *(int *)(obj + 0x390) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov198_InitSubActor;
    func_ov107_020c6624(obj, 0, (int)&Ov198_InitSubActor);
    return obj;
}
