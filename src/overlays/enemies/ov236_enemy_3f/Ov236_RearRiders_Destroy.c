/* Object teardown: release/free sub-resources and run the finaliser. */

#include "game/enemy_common.h"

struct row8 { int p; int pad; };
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov236_RearRiders_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(*(int *)(param_1 + 0x38c));
    FreeInstanceMemory(*(int *)(param_1 + 0x38c));
    FreeAllResourceTables(*(int *)(param_1 + 0x394));
    FreeInstanceMemory(*(int *)(param_1 + 0x394));
    DestroyInstance(*(int *)(param_1 + 0x388));
    Ov107_ActionResource_Destroy((char *)(*(int *)(param_1 + 0x3c8)));
    DestroyInstance(*(int *)(param_1 + 0x390));
    for (i = 0; i < 4; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3cc))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3cc));
    Ov107_DestroyObject(param_1);
}
