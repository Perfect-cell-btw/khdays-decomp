extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int flag);
extern void Ov124_ConstructShot(void);

void *Ov124_Actor_New(void *a) {
    void *obj = CallocInstance(0x3a0);
    *(void **)((char *)obj + 0x38c) = a;
    *(void **)((char *)obj + 0x18c) = Ov124_ConstructShot;
    func_ov107_020c6624(obj, 0);
    return obj;
}
