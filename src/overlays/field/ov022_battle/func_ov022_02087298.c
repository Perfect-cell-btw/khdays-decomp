/* Hides a player's render entity, stops its sound and clears its group. */

#include "game/engine.h"

extern void Entity_SetVisible(int arg0, int arg1);
extern void SNDi_ProcessEntryAlt(int arg0);
void func_ov022_02087298(int arg0) {
    int e = GetEntryField20ByIndex(arg0);
    char c;
    if (e == 0) return;
    c = *(char *)(e + 0x4bc);
    Entity_SetVisible(c, 0);
    SNDi_ProcessEntryAlt(c);
    *(short *)(e + 0x66) = -1;
}
