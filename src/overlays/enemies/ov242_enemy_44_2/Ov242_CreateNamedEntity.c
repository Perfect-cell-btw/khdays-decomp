extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov242_020d48f8;
extern void Ov242_Construct(void *obj);

void *Ov242_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3c0);

    *(signed char *)((int)obj + 0x19c) = 0x44;
    OS_SPrintf(name, &data_ov242_020d48f8);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov242_Construct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
