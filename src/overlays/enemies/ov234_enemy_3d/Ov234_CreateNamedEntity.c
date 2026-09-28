/* Creates enemy 0x3d's actor: opens its cached resource by name and initialises it. */

extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov234_020cd120;
extern void Ov234_InitEffectActor(void *obj);

void *Ov234_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3c4);

    *(signed char *)((int)obj + 0x19c) = 0x3d;
    OS_SPrintf(name, &data_ov234_020cd120);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov234_InitEffectActor;
    func_ov107_020c6624(obj, arg);
    return obj;
}
