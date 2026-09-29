/* Tear down the actor: destroy the work list (+0x394), clear +0x3a0, release the two
 * main handles (+0x384 render, +0x388 anim), free all 8 slot handles at +0x3b8, then
 * release the handle table and the actor itself. */

#include "game/enemy_common.h"

extern void FreeAllResourceTables(int a);
extern void DestroyInstance(int a);
extern void FreeInstanceMemory(int a);
extern void Ov107_DestroyObject(int a);
struct row8_020cc45c { int p; int q; };
void Ov232_Destroy(int param_1) {
    int i;
    FreeAllResourceTables(param_1 + 0x394);
    *(int *)(param_1 + 0x3a0) = 0;
    DestroyInstance(*(int *)(param_1 + 0x384));
    Ov107_ActionResource_Destroy((char *)(*(int *)(param_1 + 0x388)));
    for (i = 0; i < 8; i++) {
        DestroyInstance(((struct row8_020cc45c *)*(int *)(param_1 + 0x3b8))[i].p);
    }
    FreeInstanceMemory(*(int *)(param_1 + 0x3b8));
    Ov107_DestroyObject(param_1);
}
