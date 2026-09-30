/* Construct a named object: allocate 0x410 bytes, format a debug name via OS_SPrintf,
 * register it (+0x1a4), install the 020d1aa0 callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov209_020d6640[];
extern void Ov209_EnemyConstruct(int);
int Ov209_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x410);
    *(signed char *)(obj + 0x19c) = 42;
    OS_SPrintf(buf, data_ov209_020d6640, 42);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov209_EnemyConstruct;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
