/* Entity factory: allocates the enemy object, records its class id, opens its Ms/ resource by the
 * formatted class name, installs the class initialiser as the state callback (+0x18c) and hands the
 * object to the shared enemy framework. */

#include "game/enemy_common.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov120_020cdf20[];
extern void Ov120_InitializeActor(int);

int Ov120_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x3a8);
    *(signed char *)(obj + 0x19c) = 4;
    OS_SPrintf(buf, data_ov120_020cdf20, 4);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)Ov120_InitializeActor;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
