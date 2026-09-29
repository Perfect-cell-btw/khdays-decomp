/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class constructor as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

#include "game/enemy_common.h"

extern void OS_SPrintf(void *buffer, void *format);
extern int data_ov291_020cd620;
extern void *CallocInstance(int size);
extern void func_ov107_020c6624(void *obj, int arg);
extern void Ov291_EnemyConstruct(void *obj);

void *Ov291_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3b0);

    *(signed char *)((int)obj + 0x19c) = 0x6d;
    OS_SPrintf(name, &data_ov291_020cd620);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov291_EnemyConstruct;
    func_ov107_020c6624(obj, arg);
    return obj;
}
