/* Object teardown: release/free sub-resources and run the finaliser. */

#include "game/enemy_common.h"

struct row8 { int p; int pad; };
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov235_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(*(int *)(param_1 + 0x388));
    FreeInstanceMemory(*(int *)(param_1 + 0x388));
    FreeAllResourceTables(*(int *)(param_1 + 0x390));
    FreeInstanceMemory(*(int *)(param_1 + 0x390));
    FreeAllResourceTables(*(int *)(param_1 + 0x398));
    FreeInstanceMemory(*(int *)(param_1 + 0x398));
    Ov107_ActionResource_Destroy((char *)(*(int *)(param_1 + 0x3a8)));
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x38c));
    DestroyInstance(*(int *)(param_1 + 0x394));
    for (i = 0; i < 11; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3bc))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3bc));
    Ov107_DestroyObject(param_1);
}
