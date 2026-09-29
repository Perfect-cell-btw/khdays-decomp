/* Host only: puts the actor into state 0xe. */

#include "game/engine.h"

extern void Ov022_EnterState0E(int arg0);
void func_ov022_020ad338(int arg0) {
    if (Session_GetLocalPlayerIndex() != 0) return;
    Ov022_EnterState0E(arg0);
}
