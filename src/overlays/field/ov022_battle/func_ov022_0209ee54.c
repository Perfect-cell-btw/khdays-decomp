/* Returns a player's actor when it is alive, in the group and not in the exclusion list; otherwise
 * 0. */

#include "game/engine.h"

extern int Ov022_GetEntryField12(int a);
extern int Ov022_GetEntryField66(int a);

int func_ov022_0209ee54(int param_1, int param_2, int param_3, int param_4) {
    int sVar2 = Ov022_GetEntryField12(param_2);
    int iVar3;
    int iVar4;
    int bVar1;
    if (sVar2 <= 0) {
        return 0;
    }
    iVar3 = Ov022_GetEntryField66(param_2);
    if (param_3 != iVar3) {
        return 0;
    }
    iVar3 = GetEntryField20ByIndex(param_2);
    if (param_4 == 0) {
        return iVar3;
    }
    bVar1 = 0;
    iVar4 = 0;
    do {
        if ((int)((unsigned int)*(unsigned char *)(iVar3 + 9) * 0x800) ==
            ((short *)param_4)[iVar4]) {
            bVar1 = 1;
            break;
        }
        iVar4 = iVar4 + 1;
    } while (iVar4 < 8);
    if (bVar1 != 0) {
        iVar3 = 0;
    }
    return iVar3;
}
