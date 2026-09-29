/* Creates enemy 0x73's actor: opens its cached resource by name and initialises it. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov299_020d4e00;
extern void Ov299_Actor_InitCallbacksAndChildren(void *obj);

void *Ov299_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x394);

    *(signed char *)((int)obj + 0x19c) = 0x73;
    OS_SPrintf(name, (const char *)&data_ov299_020d4e00, 0x73);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov299_Actor_InitCallbacksAndChildren;
    func_ov107_020c6624(obj, arg);
    return obj;
}
