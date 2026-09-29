/* Destroys the models and attached instances (freeing their table), then the base object. */

#include "game/enemy_common.h"

/* Teardown with an extra ov107 release. */
struct row8 { int p; int pad; };
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov158_Destroy(int param_1) {
    int i;
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(param_1 + 0x39c)));
    for (i = 0; i < 8; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x390))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x390));
    Ov107_DestroyObject(param_1);
}
