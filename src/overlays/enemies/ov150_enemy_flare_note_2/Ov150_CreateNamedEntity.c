/* Creates enemy 18's actor: opens its cached resource by name and initialises it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov150_020d25c0[];
extern void Ov150_ActorInit(int);

int Ov150_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3d4);
    *(signed char *)(obj + 0x19c) = 18;
    OS_SPrintf(buf, data_ov150_020d25c0, 18);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov150_ActorInit;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
