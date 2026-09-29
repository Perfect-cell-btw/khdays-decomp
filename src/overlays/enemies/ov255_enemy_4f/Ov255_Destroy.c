/* Object teardown: release/free sub-resources and run the finaliser. */

#include "game/enemy_common.h"

struct row8 { int p; int pad; };
extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
void Ov255_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(*(int *)(param_1 + 0x388));
    FreeInstanceMemory(*(int *)(param_1 + 0x388));
    FreeAllResourceTables(*(int *)(param_1 + 0x390));
    FreeInstanceMemory(*(int *)(param_1 + 0x390));
    Ov107_ActionResource_Destroy((char *)(*(int *)(param_1 + 0x3a4)));
    DestroyInstance(*(int *)(param_1 + 0x384));
    DestroyInstance(*(int *)(param_1 + 0x38c));
    for (i = 0; i < 12; i++)
        DestroyInstance(((struct row8 *)*(int *)(param_1 + 0x3ec))[i].p);
    FreeInstanceMemory(*(int *)(param_1 + 0x3ec));
    FreeInstanceMemory(*(int *)(param_1 + 0x3f0));
    Ov107_DestroyObject(param_1);
}
