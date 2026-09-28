extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov286_020d4580;
extern void Ov286_ClassInit(void *obj);

void *Ov286_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x390);

    *(signed char *)((int)obj + 0x19c) = 0x6a;
    OS_SPrintf(name, &data_ov286_020d4580);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov286_ClassInit;
    func_ov107_020c6624(obj, arg);
    return obj;
}
