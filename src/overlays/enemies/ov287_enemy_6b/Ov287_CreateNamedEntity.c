extern int data_ov287_020d16e0;
extern void OS_SPrintf(void *buffer, void *format);
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void Ov287_Actor_InitClassAndSpawnParts(void *obj);

void *Ov287_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3d0);

    *(signed char *)((int)obj + 0x19c) = 0x6b;
    OS_SPrintf(name, &data_ov287_020d16e0);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov287_Actor_InitClassAndSpawnParts;
    func_ov107_020c6624(obj, arg);
    return obj;
}
