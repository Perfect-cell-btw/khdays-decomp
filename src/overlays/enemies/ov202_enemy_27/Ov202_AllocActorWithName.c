/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class constructor as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

extern void OS_SPrintf(void *buffer, void *format);
extern int data_ov202_020cefe0;
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void Ov202_Construct(void *obj);

void *Ov202_AllocActorWithName(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x414);

    *(signed char *)((int)obj + 0x19c) = 0x27;
    OS_SPrintf(name, &data_ov202_020cefe0);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov202_Construct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
