extern void OS_SPrintf(void *buffer, void *format);
extern int data_ov264_020cec20;
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void Ov264_initActor(void *obj);

void *Ov264_AllocActorWithName(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x468);

    *(signed char *)((int)obj + 0x19c) = 0x58;
    OS_SPrintf(name, &data_ov264_020cec20);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov264_initActor;
    func_ov107_020c6624(obj, arg);
    return obj;
}
