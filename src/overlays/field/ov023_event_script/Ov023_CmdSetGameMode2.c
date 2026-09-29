/* Notify func_ov002_0206d31c, request mode 2 via SetGameMode, return 1. */

#include "game/engine.h"

extern void func_ov002_0206d31c(int arg);
int Ov023_CmdSetGameMode2(int param_1) {
    func_ov002_0206d31c(param_1);
    SetGameMode(2);
    return 1;
}
