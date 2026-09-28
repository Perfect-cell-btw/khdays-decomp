/* Creates enemy 0x45's actor: opens its cached resource by name and initialises it. */

extern int data_ov243_020d476c;
extern void OS_SPrintf(void *buffer, void *format);
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void Ov243_Construct(void *obj);

void *Ov243_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3b4);

    *(signed char *)((int)obj + 0x19c) = 0x45;
    OS_SPrintf(name, &data_ov243_020d476c);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov243_Construct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
