/* Creates enemy 0x75's actor: opens its cached resource by name and initialises it. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov301_020cc760;
extern void Ov301_InitObject(void *obj);

void *Ov301_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x394);

    *(signed char *)((int)obj + 0x19c) = 0x75;
    OS_SPrintf(name, (const char *)&data_ov301_020cc760, 0x75);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov301_InitObject;
    func_ov107_020c6624(obj, arg);
    return obj;
}
