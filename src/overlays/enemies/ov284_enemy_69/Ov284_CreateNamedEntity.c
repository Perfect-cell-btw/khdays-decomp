/* Creates enemy 0x69's actor: opens its cached resource by name and initialises it. */

extern void OS_SPrintf(void *buffer, void *format);
extern int data_ov284_020cd600;
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void Ov284_InitializeActor(void *obj);

void *Ov284_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3b4);

    *(signed char *)((int)obj + 0x19c) = 0x69;
    OS_SPrintf(name, &data_ov284_020cd600);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov284_InitializeActor;
    func_ov107_020c6624(obj, arg);
    return obj;
}
