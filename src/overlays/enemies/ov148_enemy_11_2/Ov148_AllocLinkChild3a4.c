extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov148_InitSubActor();

int Ov148_AllocLinkChild3a4(int this_) {
    int obj = CallocInstance(0x3a4);
    *(int *)(obj + 0x390) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov148_InitSubActor;
    func_ov107_020c6624(obj, 0, (int)&Ov148_InitSubActor);
    return obj;
}
