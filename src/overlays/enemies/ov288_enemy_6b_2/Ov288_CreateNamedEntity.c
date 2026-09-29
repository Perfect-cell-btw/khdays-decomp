/* Creates enemy 0x6b's actor: opens its cached resource by name and initialises it. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov288_020d5320;
extern void Ov288_Actor_InitClassAndSpawnParts(void *obj);

void *Ov288_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3d0);

    *(signed char *)((int)obj + 0x19c) = 0x6b;
    OS_SPrintf(name, (const char *)&data_ov288_020d5320, 0x6b);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov288_Actor_InitClassAndSpawnParts;
    func_ov107_020c6624(obj, arg);
    return obj;
}
