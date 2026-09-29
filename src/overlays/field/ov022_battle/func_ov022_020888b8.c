/* Host only: forwards a value to a player's actor. */

#include "game/engine.h"

extern void func_ov022_020ad838(int arg0, int arg1);
void func_ov022_020888b8(int arg0, int arg1) {
    int e;
    if (Session_GetLocalPlayerIndex() != 0) return;
    e = GetEntryField20ByIndex(arg0);
    if (e == 0) return;
    func_ov022_020ad838(e, arg1);
}
