extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov262_020d51c0;
extern void Ov262_EnemyConstruct(void *obj);

void *Ov262_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3b0);

    *(signed char *)((int)obj + 0x19c) = 0x55;
    OS_SPrintf(name, &data_ov262_020d51c0);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov262_EnemyConstruct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
