/* Construct a named object: allocate 0x464 bytes, open the resource pack Ms/<id>.p of Tailbunker
 * (its handle goes to +0x1a4), install the 020cfdbc callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"
#include "game/enemy_id.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov221_020d4e00[];
extern void Ov221_EnemyInit(int);
int Ov221_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x464);
    *(signed char *)(obj + 0x19c) = 0x33;
    OS_SPrintf(buf, data_ov221_020d4e00, ENEMY_TAILBUNKER);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov221_EnemyInit;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
