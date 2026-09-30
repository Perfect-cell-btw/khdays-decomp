/* Construct a named object: allocate 0x65c bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020ce43c callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov266_020d3f60[];
extern void Ov266_Construct(int);
int Ov266_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x65c);
    *(signed char *)(obj + 0x19c) = 0x5a;
    OS_SPrintf(buf, data_ov266_020d3f60, 90);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov266_Construct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
