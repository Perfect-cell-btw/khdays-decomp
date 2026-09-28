extern void OS_SPrintf(void *buffer, void *format);
extern int data_ov216_020cec40;
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void Ov216_Construct(void *obj);

void *Ov216_AllocActorWithName(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x468);

    *(signed char *)((int)obj + 0x19c) = 0x2f;
    OS_SPrintf(name, &data_ov216_020cec40);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov216_Construct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
