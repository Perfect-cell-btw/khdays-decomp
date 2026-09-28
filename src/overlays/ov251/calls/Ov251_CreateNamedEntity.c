extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov251_020d6540;
extern void Ov251_Construct(void *obj);

void *Ov251_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3a8);

    *(signed char *)((int)obj + 0x19c) = 0x4b;
    OS_SPrintf(name, &data_ov251_020d6540);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov251_Construct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
