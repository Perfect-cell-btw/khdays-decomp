extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int flag);
extern void Ov152_ConstructPet(void);

void *Ov152_New(void *a) {
    void *obj = CallocInstance(0x3a8);
    *(void **)((char *)obj + 0x38c) = a;
    *(void **)((char *)obj + 0x18c) = Ov152_ConstructPet;
    func_ov107_020c6624(obj, 0);
    return obj;
}
