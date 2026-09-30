/* Creates enemy 0x74's actor: opens its cached resource by name and initialises it. */

#include "game/enemy_common.h"

extern void *CallocInstance(int size);
extern int OS_SPrintf(char *dst, const char *fmt, ...);
extern void func_ov107_020c6624(void *obj, int arg);
extern int data_ov300_020cbfe0;
extern void Ov300_ConstructNoOp(void *obj);

void *Ov300_CreateNamedEntity(int arg)
{
    char name[0x1d] = { 0 };
    void *obj = CallocInstance(0x3a0);

    *(signed char *)((int)obj + 0x19c) = 0x74;
    OS_SPrintf(name, (const char *)&data_ov300_020cbfe0, 0x74);
    *(int *)((int)obj + 0x1a4) = Ov107_OpenCachedResourceByName(name);
    *(void **)((int)obj + 0x18c) = Ov300_ConstructNoOp;
    func_ov107_020c6624(obj, arg);
    return obj;
}
