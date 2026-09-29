/* Construct a named object: allocate 0x4d0 bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020cc08c callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov237_020d1c88[];
extern void Ov237_Construct(int);
int Ov237_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x4d0);
    *(signed char *)(obj + 0x19c) = 64;
    OS_SPrintf(buf, data_ov237_020d1c88, 64);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov237_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
