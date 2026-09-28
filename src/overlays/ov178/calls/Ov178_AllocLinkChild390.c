extern int CallocInstance();
extern void func_ov107_020c6624();
extern void Ov178_Construct_2();

int Ov178_AllocLinkChild390(int this_) {
    int obj = CallocInstance(0x390);
    *(int *)(obj + 0x388) = this_;
    *(int *)(obj + 0x18c) = (int)&Ov178_Construct_2;
    func_ov107_020c6624(obj, 0, (int)&Ov178_Construct_2);
    return obj;
}
