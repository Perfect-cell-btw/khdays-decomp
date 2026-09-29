/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class initialiser as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov296_020d6160;
extern void Ov296_InitEnemy(void *obj);

void *Ov296_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x394);

    *(signed char *)((int)obj + 0x19c) = 0x70;
    OS_SPrintf(name, (const char *)&data_ov296_020d6160, 0x70);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov296_InitEnemy;
    func_ov107_020c6624(obj, arg);
    return obj;
}
