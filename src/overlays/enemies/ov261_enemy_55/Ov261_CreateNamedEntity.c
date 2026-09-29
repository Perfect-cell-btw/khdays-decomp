/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class constructor as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov261_020d1580;
extern void Ov261_EnemyConstruct(void *obj);

void *Ov261_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3b0);

    *(signed char *)((int)obj + 0x19c) = 0x55;
    OS_SPrintf(name, (const char *)&data_ov261_020d1580, 0x55);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov261_EnemyConstruct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
