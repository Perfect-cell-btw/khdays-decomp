/* Construct a named object: allocate 0x528 bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020cbfc8 callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov254_020d5980[];
extern void Ov254_Construct(int);
int Ov254_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x528);
    *(signed char *)(obj + 0x19c) = 0x4e;
    OS_SPrintf(buf, data_ov254_020d5980, 78);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov254_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
