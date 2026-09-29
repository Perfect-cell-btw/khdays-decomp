/* Creates enemy 0x6e's actor: opens its cached resource by name and initialises it. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov292_020d48c0;
extern void Ov292_InitNamedEntityActor(void *obj);

void *Ov292_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3bc);

    *(signed char *)((int)obj + 0x19c) = 0x6e;
    OS_SPrintf(name, (const char *)&data_ov292_020d48c0, 0x6e);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov292_InitNamedEntityActor;
    func_ov107_020c6624(obj, arg);
    return obj;
}
