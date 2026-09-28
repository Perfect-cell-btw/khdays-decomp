/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class initialiser as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

extern void *CallocInstance(int size);
extern void OS_SPrintf(void *buffer, void *format);
extern int Ov107_OpenCachedResourceByName(void *name);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov240_020cfb80;
extern void Ov240_InitializeActor(void *obj);

void *Ov240_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3c4);

    *(signed char *)((int)obj + 0x19c) = 0x43;
    OS_SPrintf(name, &data_ov240_020cfb80);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov240_InitializeActor;
    func_ov107_020c6624(obj, arg);
    return obj;
}
