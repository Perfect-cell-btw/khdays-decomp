/* Construct a named object: allocate 0x464 bytes, open the resource pack Ms/<id>.p of Tailbunker
 * (its handle goes to +0x1a4), install the 020d1bdc callback (+0x18c) and init. Return it. */

#include "game/enemy_common.h"
#include "game/enemy_id.h"

extern int CallocInstance(int a);
extern void OS_SPrintf(char *buf, const char *fmt, int a);
extern void func_ov107_020c6624(int a, int b);
extern const char data_ov222_020d6c20[];
extern void Ov222_EnemyInit(int);
int Ov222_CreateNamedEntity(int param_1) {
    char buf[0x1d] = {0};
    int obj = CallocInstance(0x464);
    *(signed char *)(obj + 0x19c) = 0x33;
    OS_SPrintf(buf, data_ov222_020d6c20, ENEMY_TAILBUNKER);
    *(int *)(obj + 0x1a4) = Ov107_OpenCachedResourceByName(buf);
    *(int *)(obj + 0x18c) = (int)&Ov222_EnemyInit;
    func_ov107_020c6624(obj, param_1);
    return obj;
}
