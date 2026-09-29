/* Script command: runs the ov002 handler, then sets game mode 2; returns 1. */

#include "game/engine.h"

/* Twin of Ov023_CmdSetGameMode2. */
extern void func_ov002_0206d31c(int arg);
int Ov106_CmdSetGameMode2(int param_1) {
    func_ov002_0206d31c(param_1);
    SetGameMode(2);
    return 1;
}
