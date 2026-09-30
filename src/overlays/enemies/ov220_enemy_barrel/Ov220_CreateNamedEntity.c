/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class constructor as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

#include "game/enemy_common.h"

extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern int data_ov220_020d3ba0;
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern void Ov220_Construct(void *obj);

void *Ov220_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3dc);

    *(signed char *)((int)obj + 0x19c) = 0x32;
    OS_SPrintf(name, (const char *)&data_ov220_020d3ba0, 0x32);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov220_Construct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
