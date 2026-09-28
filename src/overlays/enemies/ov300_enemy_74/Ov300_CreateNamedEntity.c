/* Creates enemy 0x74's actor: opens its cached resource by name and initialises it. */

extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov300_020cbfe0;
extern void Ov300_ConstructNoOp(void *obj);

void *Ov300_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3a0);

    *(signed char *)((int)obj + 0x19c) = 0x74;
    OS_SPrintf(name, &data_ov300_020cbfe0);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov300_ConstructNoOp;
    func_ov107_020c6624(obj, arg);
    return obj;
}
