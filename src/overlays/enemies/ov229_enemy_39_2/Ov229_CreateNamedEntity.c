/* Construct a named object: allocate 0x4f8 bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020d1b18 callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov229_020d6920[];
extern void Ov229_Construct(int);
int Ov229_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x4f8);
    *(signed char *)(obj + 0x19c) = 0x39;
    OS_SPrintf(buf, data_ov229_020d6920, 57);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov229_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
